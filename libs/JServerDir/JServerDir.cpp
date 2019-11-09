#include "pch.h"
#include "JServerDir.h"
#include "IServerDir.h"
#include "AutoMessage.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "Helpers.h"
#include "NetDefs.h"
#include "UDPSocket.h"
#include "TCPSocket.h"
#include <exception>

//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <thread>
#include <map>
#include <time.h>
#include <chrono>
//

extern ILTCommon* g_pCommonLT;

JServerDir* g_pJServerDir;

JServerDir::JServerDir(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule)
{
	m_bClientSide = bClientSide;
	m_pLTCSBase = &ltCSBase;
	m_hResourceModule = hResourceModule;
	m_nActivePeer = -1;
	m_bIsRequestQueueRunning = false;

	g_pCommonLT = m_pLTCSBase->Common();

	g_pJServerDir = this;
}

JServerDir::~JServerDir()
{
	if (m_bIsRequestQueueRunning) {
		m_bStopThread = true;
		Sleep(1000);

		// Regrettably use windows api
		WaitForSingleObject(m_tRequestQueue.native_handle(), INFINITE);
	}

	g_pJServerDir = NULL;
}

//////////////////////////////////////////////////////////////////////////////
// Request handling

// Add a request to the end of the queue
// Returns false if unable to add the request to the queue
// Note : A return value of true does NOT imply that the request completed
// successfully.
bool JServerDir::QueueRequest(ERequest eNewRequest)
{

	if (eNewRequest == ERequest::eRequest_Validate_Version
		|| eNewRequest == ERequest::eRequest_MOTD) {
		return true;
	}

	if (!m_bIsRequestQueueRunning) {
		m_bStopThread = false;
		m_tRequestQueue = std::thread(&JServerDir::RequestQueueLoop, this);
		m_tRequestQueue.detach();
		m_bIsRequestQueueRunning = true;
	}

	Job eJob;

	if (eNewRequest == ERequest::eRequest_Update_List) {
		eJob = { eJobRequest_Query_Master_Server, "", {} };
	}
	else if (eNewRequest == ERequest::eRequest_Publish_Server) {
		Peer peer = *m_Peers.at(m_nActivePeer);
		eJob = { eJobRequest_Publish_Server, "", peer };
	}

	AddJob(eJob);
	SwitchStatus(eStatus_Processing);

	return true;
}

// Add a list of requests to the queue
// Returns false if any of the requests could not be added.  (And does not
// add any of them in that case.)
bool JServerDir::QueueRequestList(const TRequestList& cNewRequests)
{
	return false;
}

// Retrieve the list of waiting requests.  
// The first entry is the entry which is currently being processed.
IServerDirectory::TRequestList JServerDir::GetWaitingRequestList() const
{
	return TRequestList();
}

// Clear the request list
// Note : Request list processing must be paused to clear the request list
// Returns false if the request list is currently being processed.
bool JServerDir::ClearRequestList()
{
	if (m_bProcessJobs) {
		return false;
	}

	SwitchStatus(eStatus_Waiting);

	m_mJobMutex.lock();
	m_vJobs.clear();
	m_mJobMutex.unlock();

	return true;
}

// Pause processing, process the given request, return the result,
// and go back to the previous state.
// Returns the result of the request
IServerDirectory::ERequestResult JServerDir::ProcessRequest(ERequest eNewRequest, uint32 nTimeout)
{
	return eRequestResult_Success;
}

// Pauses the request list processing
// Note : This will cancel the active request, and schedule it for 
// re-processing when processing is resumed.
bool JServerDir::PauseRequestList()
{
	m_bProcessJobs = false;

	// TODO: Pause the active request (Maybe store the last ran job?)

	return true;
}
// Process (or continue processing) the request list
bool JServerDir::ProcessRequestList()
{
	m_bProcessJobs = true;

	// TODO: Resume the last ran job

	return true;
}

// Wait until the next request is completed and return the result
IServerDirectory::ERequestResult JServerDir::BlockOnActiveRequest(uint32 nTimeout)
{
	Sleep(nTimeout);
	return eRequestResult_Success;
}
// Wait until the next request matching eBlockRequest is completed and 
// return its result
// Note : Returns eRequestResult_Aborted if an earlier request fails
IServerDirectory::ERequestResult JServerDir::BlockOnRequest(ERequest eBlockRequest, uint32 nTimeout)
{
	Sleep(nTimeout);
	return eRequestResult_Success;
}
// Wait until the next request matching one of the entries in 
// eBlockRequestList is completed and return its result
// Note : Returns eRequestResult_Aborted if an earlier request fails
IServerDirectory::ERequestResult JServerDir::BlockOnRequestList(const TRequestList& cBlockRequestList, uint32 nTimeout)
{
	Sleep(nTimeout);
	return eRequestResult_Success;
}
// Wait until we go out of the processing state
IServerDirectory::ERequestResult JServerDir::BlockOnProcessing(uint32 nTimeout)
{
	Sleep(nTimeout);
	return eRequestResult_Success;
}

// Is this request in request list?
bool JServerDir::IsRequestPending(ERequest ePendingRequest) const
{
	if (m_Peers.size() == 0) {
		return true;
	}

	return false;
}

// Returns the most recently successful request
IServerDirectory::ERequest JServerDir::GetLastSuccessfulRequest() const
{
	return IServerDirectory::eRequest_Nothing;
}
// Returns the most recently failed request
IServerDirectory::ERequest JServerDir::GetLastErrorRequest() const
{
	return IServerDirectory::eRequest_Nothing;
}
// Returns the currently active request
IServerDirectory::ERequest JServerDir::GetActiveRequest() const
{
	return IServerDirectory::eRequest_Nothing;
}

// Get the most recently processed request
IServerDirectory::ERequest JServerDir::GetLastRequest() const
{
	return IServerDirectory::eRequest_Nothing;
}
// Get the result of the most recently processed result
IServerDirectory::ERequestResult JServerDir::GetLastRequestResult() const
{
	return eRequestResult_Success;
}
// Get the string associated with the most recently processed result
const char* JServerDir::GetLastRequestResultString() const
{
	return "T E S T";
}

//////////////////////////////////////////////////////////////////////////////
// Status

// Get the current status
IServerDirectory::EStatus JServerDir::GetCurStatus() const
{
	return (EStatus)m_iStatus.load();
}

// Get the descriptive text associated with the current status
const char* JServerDir::GetCurStatusString() const
{

#ifdef _DROPIN
	// This is really stupid,
	// but since this suppose to be compatible as a drop-in replacement
	// We need a place to run our update, and this function gets called every ScreenJoin Update!
	g_pJServerDir->Update();
#endif


	switch (m_iStatus.load()) {
	case IServerDirectory::eStatus_Error:
		return "Error";
	case IServerDirectory::eStatus_Paused:
		return "Paused";
	case IServerDirectory::eStatus_Processing:
		return "Processing";
	case IServerDirectory::eStatus_TotalNum:
		return "You shouldn't get this >:(";
	case IServerDirectory::eStatus_Waiting:
		return "Waiting";
	}

	return "Unknown";
}

//////////////////////////////////////////////////////////////////////////////
// Startup - service specific.

void JServerDir::SetStartupInfo(ILTMessage_Read& cMsg)
{
	m_StartupInfo.m_sGameSpyName = "";
	m_StartupInfo.m_sGameSpySecretKey = "";

	//	cMsg.Writeuint32(( uint32 )&startupInfo );

	StartupInfo_Titan* pStartupInfo = (StartupInfo_Titan*)cMsg.Readuint32();

	m_StartupInfo = *pStartupInfo;
}

void JServerDir::GetStartupInfo(ILTMessage_Write& cMsg)
{
	cMsg.Writeuint32((uint32)&m_StartupInfo);
}

//////////////////////////////////////////////////////////////////////////////
// Game name

void JServerDir::SetGameName(const char* pName)
{
	m_sGameName = pName;
}

const char* JServerDir::GetGameName() const
{
	return m_sGameName.c_str();
}


//////////////////////////////////////////////////////////////////////////////
// CD Keys
// Fake keys work okay!
//

bool JServerDir::SetCDKey(const char* pKey)
{
	return true;
}

bool JServerDir::GetCDKey(std::string* pKey)
{
	*pKey = FAKE_CD_KEY;
	return true;
}

bool JServerDir::IsCDKeyValid() const
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
// Game Version

// Set the current version
void JServerDir::SetVersion(const char* pVersion)
{
	m_sVersion = pVersion;
}

// Set the current region
void JServerDir::SetRegion(const char* pRegion)
{
	m_sRegion = pRegion;
}

// Is the current version valid?
// Note : Returns false if eRequest_Validate_Version has not been processed
bool JServerDir::IsVersionValid() const
{
	return true;
}

// Is the current version the newest version?
// Note : Returns false if eRequest_Validate_Version has not been processed
bool JServerDir::IsVersionNewest() const
{
	return true;
}

// Is a patch available?
// Note : Returns false if eRequest_Validate_Version has not been processed
bool JServerDir::IsPatchAvailable() const
{
	return false;
}

//////////////////////////////////////////////////////////////////////////////
// Message of the Day

// Is the MOTD "new"?
// Note : Returns false if eRequest_MOTD has not been processed
bool JServerDir::IsMOTDNew(EMOTD eMOTD) const
{
	return false;
}

// Get the current MOTD
char const* JServerDir::GetMOTD(EMOTD eMOTD) const
{
	if (eMOTD == eMOTD_Game) {
		return "Welcome to NOLF2 online!\nMake sure to check out https://www.spawnsite.net/ for the latest map packs.";
	}


	return "Master server provided by QTracker.\nVisit https://www.qtracker.com/ for more information.";
}

//////////////////////////////////////////////////////////////////////////////
// Active peer info

// Sets the active peer address and port
// Note : Use NULL to indicate the local machine
// Returns false if there was some problem
bool JServerDir::SetActivePeer(const char* pAddr)
{
	std::string activePeer = "";

	// Protect against null
	if (pAddr == NULL) {
		activePeer = LOCAL_PEER;
	}
	else {
		activePeer = pAddr;
	}

	// See if we're already in the list!
	int index = 0;
	for (auto peer : m_Peers) {
		if (peer->GetAddress().compare(activePeer) == 0) {
			m_nActivePeer = index;
			return true;
		}
		index++;
	}


	Peer* peer = new Peer();

	peer->SetAddress(activePeer);

	// TODO: High precision timer? Not sure if it's needed here. 
	peer->SetCreatedAt(m_pLTCSBase->GetTime());

	// Throw in our new ActivePeer(TM)
	//m_PeerList.push_back(pAddr);
	m_Peers.push_back(peer);
	m_nActivePeer = m_Peers.size() - 1;

	return true;
}

// Get the currently selected active peer
// Returns false if there was some problem  (e.g. a null parameter)
bool JServerDir::GetActivePeer(std::string* pAddr, bool* pLocal) const
{
	// Peer not set!
	if (m_nActivePeer == NO_ACTIVE_PEER || pAddr == NULL || pLocal == NULL) {
		return false;
	}

	Peer* peer = m_Peers.at(m_nActivePeer);
	std::string activePeer = peer->GetAddress();

	if (activePeer.compare(LOCAL_PEER)) {
		pAddr = NULL;
		*pLocal = true;
		return true;
	}

	pAddr = &activePeer;
	*pLocal = false;
	return true;
}

// Remove the active peer from the peer list
// The active peer will be set to the local machine
// Returns false if the peer is the local machine
bool JServerDir::RemoveActivePeer()
{
	Peer* peer = m_Peers.at(m_nActivePeer);

	if (peer->GetAddress().compare(LOCAL_PEER)) {
		return false;
	}

	// Remove it from the list
	m_Peers.erase(m_Peers.begin() + m_nActivePeer);

	// Now remove it
	delete peer;

	m_nActivePeer = NO_ACTIVE_PEER;

	return true;
}

// Change the active peer info
bool JServerDir::SetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Read& cMsg)
{
	if (m_nActivePeer == NO_ACTIVE_PEER || eInfoType >= ePeerInfo_TotalNum) {
		return false;
	}

	Peer* peer = m_Peers.at(m_nActivePeer);

	switch (eInfoType) {
	case ePeerInfo_Age:
		peer->SetCreatedAt(cMsg.Readfloat());
		break;
	case ePeerInfo_Details:
	{
		PeerInfo_Details* details = &peer->m_DetailsData;
		details->bUseSkills = cMsg.Readbool();
		details->bFriendlyFire = cMsg.Readbool();
		details->nMPDifficulty = cMsg.Readuint8();
		details->fPlayerDiffFactor = cMsg.Readfloat();

		bool containsPlayerData = cMsg.Readbool();

		// Loop until we hit false
		while (containsPlayerData) {
			PeerInfo_PlayerDetails playerDetails;

			char buffer[MAX_PACKET_LEN];
			buffer[0] = 0;

			cMsg.ReadString(buffer, MAX_PACKET_LEN);

			playerDetails.sUniqueName = buffer;

			playerDetails.nPing = cMsg.Readuint16();

			details->Players.push_back(playerDetails);

			containsPlayerData = cMsg.Readbool();
		}

		details->nRunSpeed = cMsg.Readuint8();
		details->nScoreLimit = cMsg.Readuint8();
		details->nTimeLimit = cMsg.Readuint8();

		peer->SetHasDetailsData(true);
	}
	break;
	case ePeerInfo_Name:
		char buffer[MAX_PACKET_LEN];
		buffer[0] = 0;

		cMsg.ReadString(buffer, MAX_PACKET_LEN);

		peer->m_NameData.sHostName = buffer;

		peer->SetHasNameData(true);
		break;
	case ePeerInfo_Ping:
		peer->SetPing(cMsg.Readuint16());
		// TODO: Do this
		break;
	case ePeerInfo_Port:
		peer->m_PortData.nHostPort = cMsg.Readuint16();
		peer->SetHasPortData(true);
		break;
	case ePeerInfo_Service:
	{
		// Double pointer!
		PeerInfo_Service_Titan* pServiceInfo = (PeerInfo_Service_Titan*)cMsg.Readuint32();
		peer->m_ServiceData = *pServiceInfo;

		peer->SetHasServiceData(true);
	}
	break;
	case ePeerInfo_Summary:
	{
		PeerInfo_Summary* summary = &peer->m_SummaryData;
		char buffer[MAX_PACKET_LEN];
		buffer[0] = 0;

		cMsg.ReadString(buffer, MAX_PACKET_LEN);
		summary->sBuild = buffer;
		memset(buffer, 0, sizeof(buffer));

		cMsg.ReadString(buffer, MAX_PACKET_LEN);
		summary->sWorldName = buffer;
		memset(buffer, 0, sizeof(buffer));

		summary->nCurrentPlayers = cMsg.Readuint8();
		summary->nMaxPlayers = cMsg.Readuint8();
		summary->bUsePassword = cMsg.Readbool();
		summary->nGameType = cMsg.Readuint8();

		cMsg.ReadString(buffer, MAX_PACKET_LEN);
		summary->sModName = buffer;

		peer->SetHasSummaryData(true);
	}
	break;
	}

	return true;
}
// Has the active peer info been queried from the directory server?
// Returns true if the required information has been queried
bool JServerDir::HasActivePeerInfo(EPeerInfo eInfoType) const
{
	return false;
}
// Get the current active server info
// Returns false if that information has not been queried for the active peer,
// or if pMsg is null
bool JServerDir::GetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Write* pMsg) const
{
	if (pMsg == NULL || eInfoType >= ePeerInfo_TotalNum || m_nActivePeer == NO_ACTIVE_PEER) {
		return false;
	}

	pMsg->Reset();

	Peer* peer = m_Peers.at(m_nActivePeer);

	switch (eInfoType) {
	case ePeerInfo_Age:
		pMsg->Writefloat(peer->GetCreatedAt());
		break;
	case ePeerInfo_Details:
	{
		PeerInfo_Details* details = &peer->m_DetailsData;
		pMsg->Writebool(details->bUseSkills);
		pMsg->Writebool(details->bFriendlyFire);
		pMsg->Writeuint8(details->nMPDifficulty);
		pMsg->Writefloat(details->fPlayerDiffFactor);

		for (auto player : details->Players) {
			// Bool: Hey we have player info to read!
			pMsg->Writebool(true);

			// Player info
			pMsg->WriteString(getMsgString(player.sUniqueName));
			pMsg->Writeuint16(player.nPing);
		}

		// Tell them we're done printing out players
		pMsg->Writebool(false);

		pMsg->Writeuint8(details->nRunSpeed);
		pMsg->Writeuint8(details->nScoreLimit);
		pMsg->Writeuint8(details->nTimeLimit);
	}
	break;
	case ePeerInfo_Name:
		pMsg->WriteString(getMsgString(peer->m_NameData.sHostName));
		break;
	case ePeerInfo_Ping:
		pMsg->Writeuint16(peer->GetPing());
		break;
	case ePeerInfo_Port:
		pMsg->Writeuint16(peer->m_PortData.nHostPort);
		break;
	case ePeerInfo_Service:
	{
		// Double pointer!
		uint32 servicePointer = (uint32)&peer->m_ServiceData;
		pMsg->Writeuint32(servicePointer);
	}
	break;
	case ePeerInfo_Summary:
	{
		PeerInfo_Summary* summary = &peer->m_SummaryData;

		pMsg->WriteString(getMsgString(summary->sBuild));
		pMsg->WriteString(getMsgString(summary->sWorldName));
		pMsg->Writeuint8(summary->nCurrentPlayers);
		pMsg->Writeuint8(summary->nMaxPlayers);
		pMsg->Writebool(summary->bUsePassword);
		pMsg->Writeuint8(summary->nGameType);
		pMsg->WriteString(getMsgString(summary->sModName));
	}
	break;
	case ePeerInfo_Validated:
		pMsg->Writeuint8(1);
		break;
	}

	return true;
}

IServerDirectory::TPeerList JServerDir::GetPeerList() const
{
	TPeerList list;

	for (auto peer : m_Peers) {
		list.push_back(peer->GetAddress());
	}

	return list;
}

void JServerDir::ClearPeerList()
{
	for (auto peer : m_Peers) {
		delete peer;
	}

	m_Peers.clear();
}

bool JServerDir::HandleNetMessage(ILTMessage_Read& cMsg, const char* pSender, uint16 nPort)
{

	// We don't know any of the messages yet :thinking:
	// Probably has to do with sending the challenge to the server, and getting lists and stuff.

	return false;
}

bool JServerDir::SetNetHeader(ILTMessage_Read& cMsg)
{

	// ????

	return false;
}

void JServerDir::Update()
{
	CheckForQueuedPeers();
}

void JServerDir::QueryMasterServer()
{
	TCPSocket* pSock = new TCPSocket();

	ConnectionData connectionData = { MASTER_SERVER, MASTER_PORT };

	std::string sServerList = "";

	auto startTime = getTimestampInMs();

	try {
		pSock->Connect(connectionData);

		/* Bad way of handling challenge, server times out.
		// Say hello
		pSock->Query("", connectionData);

		std::string sChallenge = pSock->Recieve(connectionData);

		Sleep(1000);
		*/

		std::string sResponse = QUERY_UPDATE_LIST;
		sResponse += "queryid\\" + std::to_string(++m_iQueryNum) + ".1";

		pSock->Query(sResponse, connectionData);
		
		sServerList = pSock->Recieve(connectionData);

		bool done = true;
	}
	catch (std::exception ex) {
		SwitchStatus(eStatus_Error);
		delete pSock;
		pSock = NULL;

		return;
	}

	auto finishTime = getTimestampInMs();

	auto responseTime = finishTime - startTime;

	struct ipTest {
		unsigned char ip[4];
		unsigned short port;
	};

	int nCurrentPosition = 0;

	// Couldn't find anything!
	if (sServerList.empty()) {
		SwitchStatus(eStatus_Error);
		delete pSock;
		pSock = NULL;
		return;
	}

	std::string sCursor = sServerList;

	while (true) {
		// Skip the challenge if it's there.
		// Kinda bad code, but it gets the job done.
		if (sCursor.find("\\basic\\\\secure\\TXKOAT") == 0) {
			nCurrentPosition += 21;
			sCursor = sServerList.substr(nCurrentPosition, sCursor.size());
			continue;
		}

		sCursor = sServerList.substr(nCurrentPosition, sCursor.size());
		nCurrentPosition += sizeof(ipTest);

		if (sCursor.find("\\final\\") == 0) {
			break;
		}

		ipTest* serverIp = (ipTest*)sCursor.c_str();

		unsigned short nPort = htons(serverIp->port);

		std::string ipBuffer;
		char buffer[32];
		buffer[0] = '\0';

		sprintf(buffer, "%d.%d.%d.%d", serverIp->ip[0], serverIp->ip[1], serverIp->ip[2], serverIp->ip[3]);

		ipBuffer = buffer;

		// Loop through all the servers
		Job job = { eJobRequest_Query_Server, ipBuffer + ":" + std::to_string(nPort), {} };
		AddJob(job);
	}

	delete pSock;
	pSock = NULL;
}

void JServerDir::QueryServer(std::string sAddress)
{
	Peer* peer = new Peer();

	bool bResult;

	std::vector<std::string> addressInfo = splitByCharacter(sAddress, ':');
	std::string sIPAddress = addressInfo[0];
	unsigned short nPort = std::stoi(addressInfo[1]);


	{
		UDPSocket* pSock = new UDPSocket();
		ConnectionData connectionData = { sIPAddress, nPort };

		try {
			pSock->Query("\\status\\", connectionData);
		}
		catch (std::exception ex) {
			SwitchStatus(eStatus_Error);
			delete pSock;
			pSock = NULL;

			return;
		}

		Sleep(1000);

		std::string sStatus = pSock->Recieve(connectionData);

		// This server is not responding...
		if (sStatus.empty()) {
			delete pSock;
			pSock = NULL;

			return;
		}

		std::map<std::string, std::string> mappy = splitResultsToMap(sStatus);

		PeerInfo_Name name;
		name.sHostName = mappy.at("hostname");


		// Set summary data
		PeerInfo_Summary summary;
		summary.bUsePassword = std::stoi(mappy.at("password"));
		summary.nCurrentPlayers = std::stoi(mappy.at("numplayers"));
		summary.nMaxPlayers = std::stoi(mappy.at("maxplayers"));
		summary.sBuild = mappy.at("gamever");
		summary.sModName = "";//mappy.at("gamename");
		summary.sWorldName = mappy.at("mapname");

		std::string gameType = mappy.at("gametype");

		summary.nGameType = gameTypeStringToInt(gameType);

		peer->SetPing(0);

		peer->m_NameData = name;
		peer->m_SummaryData = summary;
		peer->SetHasSummaryData(true);

		// Set details data
		PeerInfo_Details details;
		// Not available?
		details.bFriendlyFire = false;
		details.bUseSkills = false;
		details.fPlayerDiffFactor = 0;
		details.nMPDifficulty = 0;
		details.nRunSpeed = 1;
		details.nScoreLimit = std::stoi(mappy.at("fraglimit"));
		details.nTimeLimit = std::stoi(mappy.at("timelimit"));

		std::vector<std::string> pingList;
		std::vector<std::string> playerList; 
		std::vector<std::string> fragList; // We don't actually use this..
		
		// Luckily mappy gives it to us in order!
		for (auto keyVal : mappy) {
			if(keyVal.first.find("ping_") == 0) {
				pingList.push_back(keyVal.second);
			}
			else if (keyVal.first.find("player_") == 0) {
				playerList.push_back(keyVal.second);
			}
			else if (keyVal.first.find("frag_") == 0) {
				fragList.push_back(keyVal.second);
			}
		}

		for (int i = 0; i < playerList.size(); i++) {
			PeerInfo_PlayerDetails player;

			player.sUniqueName = playerList.at(i);
			player.nPing = std::stoi(pingList.at(i));

			details.Players.push_back(player);
		}

		peer->m_DetailsData = details;
		peer->SetHasDetailsData(true);

		peer->SetAddress(sIPAddress);

		PeerInfo_Port port;
		port.nHostPort = nPort;
		peer->m_PortData = port;

		delete pSock;
		pSock = NULL;
	}

	PingPeer(peer);

	m_mQueuedPeerMutex.lock();
	m_QueuedPeers.push_back(peer);
	m_mQueuedPeerMutex.unlock();
}

//
// This job blocks!
//
//
void JServerDir::PublishServer(Peer peerParam)
{
	UDPSocket* uSock = new UDPSocket();

	Peer peer = peerParam;

	ConnectionData selfConnectionData = { "0.0.0.0", 27889 };
	ConnectionData masterConnectionData = { MASTER_SERVER, MASTER_PORT_UDP };
	ConnectionData incomingConnectionData = { "0.0.0.0", 0 };

	std::string heartbeat = getHeartbeat(m_iQueryNum, false);
	std::string gameInfo = encodeGameInfoToString(&peer);

	if (!m_bBoundConnection) {

		try {
			uSock->Bind(selfConnectionData);

			uSock->Query(heartbeat, masterConnectionData);

			m_bBoundConnection = true;

			Sleep(500);

		}
		catch (std::exception e) {
			std::string message = e.what();

			m_bPublishingServer = false;

			delete uSock;
			uSock = NULL;

			return;
		}

	}

	auto nCurrentTime = getTimestamp();
	auto nLastHeartbeat = getTimestamp();

	// TODO: figure out what counts as a state change
	bool bStateChanged = false;

	while (true) {

		nCurrentTime = getTimestamp();

		// Gameplay and Main ServerDir threads will pump us a Publish_Server request every 5 seconds or so.
		// So let's see if it's ready, and update our peer object!
		bool locked = m_mJobMutex.try_lock();

		if (locked) {
			if (m_vJobs.size() > 0) {
				Job job = m_vJobs.back();
				m_vJobs.pop_back();

				// Update the peer
				if (job.eRequestType == eJobRequest_Publish_Server) {
					peer = job.Peer;
				}
			}

			m_mJobMutex.unlock();
		}

		try {
			incomingConnectionData = { "0.0.0.0", 0 };

			std::string result = uSock->Recieve(incomingConnectionData);

			// Handle status requests
			if (result.find("\\status\\") != std::string::npos) {

				gameInfo = encodeGameInfoToString(&peer);
				gameInfo += std::to_string(++m_iQueryNum) + ".1";

				uSock->Query(gameInfo, incomingConnectionData);

			}

			// After 60 seconds, poke the master server
			if (bStateChanged || nCurrentTime - nLastHeartbeat > 60) {
				uSock->Query(getHeartbeat(m_iQueryNum, bStateChanged), masterConnectionData);
				nLastHeartbeat = nCurrentTime;
			}

			bStateChanged = false;
		}
		catch (std::exception e) {
			std::string message = e.what();

			// todo: log
			LPCWSTR str = (wchar_t*)message.c_str();
			OutputDebugString(str);

		}

		// If we want to stop, stop!
		if (m_bStopThread.load()) {

			// TODO: This kinda sucks. Feed it into the main loop up there.
			// Also it seems QTracker will just drop it, if we don't send it anything after a statechange. I'lllll take it!
			uSock->Query(getHeartbeat(m_iQueryNum, true), masterConnectionData);

			delete uSock;
			uSock = NULL;

			break;
		}
	}
}

//
// Ping Peer, was a job but it literally happens sequentially, so ehh.
// Takes in pointer peer instead of a copy because it gets called from QueryServer, so it doesn't need a full copy.
//
void JServerDir::PingPeer(Peer* peer)
{
	std::string pingQuery = "\\echo\\hello";

	UDPSocket* pSock = new UDPSocket();
	ConnectionData connectionData = { peer->GetAddress(), peer->m_PortData.nHostPort };

	auto startTime = getTimestampInMs();

	try {
		pSock->Query(pingQuery, connectionData);
	}
	catch (std::exception ex) {
		SwitchStatus(eStatus_Error);
		delete pSock;
		pSock = NULL;

		return;
	}

	int iterations = 0;

	// Loop until we got something, or until we hit the iteration count
	while (iterations < INVALID_PING) {

		std::string sStatus = pSock->Recieve(connectionData);

		// This server is not responding...
		if (sStatus.empty()) {
			/*
			peer->SetPing(INVALID_PING);
			delete pSock;
			pSock = NULL;
			return;
			*/

			// Affects the ping code a little bit, 
			// but we want some kind of predictable timing
			Sleep(1);
			iterations++;
			continue;
		}
		break;
	}

	auto finishTime = getTimestampInMs();

	// Short can handle 999.
	int16 responseTime = (int16)Min((long long)INVALID_PING, finishTime - startTime);

	peer->SetPing(responseTime);
	delete pSock;
	pSock = NULL;
}

void JServerDir::CheckForQueuedPeers()
{
	m_mQueuedPeerMutex.lock();
	std::vector<Peer*> queuedPeers = m_QueuedPeers;
	m_QueuedPeers.clear();
	m_mQueuedPeerMutex.unlock();
	
	for (Peer* peer : queuedPeers) {
		m_Peers.push_back(peer);
	}


	if (m_Peers.size() > 0) {
		SwitchStatus(eStatus_Waiting);
	}
}

void JServerDir::AddJob(Job eJob)
{
	m_mJobMutex.lock();
	m_vJobs.push_back(eJob);
	m_mJobMutex.unlock();
}

void JServerDir::SwitchStatus(EStatus eStatus)
{
	m_iStatus = eStatus;
}

//
// Thread loop!
//
void JServerDir::RequestQueueLoop()
{
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	m_nThreadLastActivity = getTimestamp();

	m_bPublishingServer = false;
	m_bBoundConnection = false;

	m_iQueryNum = 0;

	while (true) {
		// See if we wanna kill the thread!
		if (m_bStopThread.load()) {
			break;
		}

		Sleep(50);

		// Quite the statement...
		auto nSeconds = getTimestamp();

		// After 5 seconds of no activity, kill the thread
		if (nSeconds - m_nThreadLastActivity > 5) {
			break;
		}

		bool locked = m_mJobMutex.try_lock();

		if (!locked) {
			continue;
		}

		if (m_vJobs.size() == 0) {
			m_mJobMutex.unlock();
			continue;
		}

		Job job = m_vJobs.back();
		m_vJobs.pop_back();

		m_mJobMutex.unlock();

		switch (job.eRequestType) {
		case eJobRequest_Query_Master_Server:
			QueryMasterServer();
			break;
		case eJobRequest_Query_Server:
			QueryServer(job.sData);
			break;
		case eJobRequest_Publish_Server:
			m_bPublishingServer = true;

			// This will block, until we're done publishing.
			PublishServer(job.Peer);
			break;
		}

		// We did something, neat! So update the last activity time.
		m_nThreadLastActivity = getTimestamp();
	}

	WSACleanup();

	// We're not running anymore.
	m_bIsRequestQueueRunning = false;

	SwitchStatus(eStatus_Waiting);
}
