#include "pch.h"
#include "JServerDir.h"
#include "IServerDir.h"
#include "AutoMessage.h"
#include <WinSock2.h>
#include <WS2tcpip.h>

//
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <thread>
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
	}
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

	if (eNewRequest == ERequest::eRequest_Update_List) {

		m_mJobMutex.lock();
		m_vJobs.push_back({ eNewRequest });
		m_mJobMutex.unlock();

		m_eStatus = eStatus_Processing;
	}

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
	return false;
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
	return false;
}
// Process (or continue processing) the request list
bool JServerDir::ProcessRequestList()
{


	return false;
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
	return eRequest_Nothing;
}
// Returns the most recently failed request
IServerDirectory::ERequest JServerDir::GetLastErrorRequest() const
{
	return eRequest_Nothing;
}
// Returns the currently active request
IServerDirectory::ERequest JServerDir::GetActiveRequest() const
{
	return eRequest_Nothing;
}

// Get the most recently processed request
IServerDirectory::ERequest JServerDir::GetLastRequest() const
{
	return eRequest_Nothing;
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
	return m_eStatus;
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


	switch (m_eStatus) {
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

	StartupInfo_Titan* pStartupInfo = (StartupInfo_Titan*)&cMsg;
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
	return true;
}

// Get the current MOTD
char const* JServerDir::GetMOTD(EMOTD eMOTD) const
{
	if (eMOTD == eMOTD_Game) {
		return "Welcome to NOLF2 online!\nMake sure to check out https://www.spawnsite.net/ for the latest map packs.";
	}


	return "This is a system message:\n\n-There is no scheduled downtime\n\nWe also do not know if there will be any ever since we don't control the servers. oopsie!";
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
		}
		break;
	case ePeerInfo_Name:
		char buffer[MAX_PACKET_LEN];
		buffer[0] = 0;

		cMsg.ReadString(buffer, MAX_PACKET_LEN);

		peer->m_NameData.sHostName = buffer;
		break;
	case ePeerInfo_Ping:
		peer->SetPing(cMsg.Readuint16());
		// TODO: Do this
		break;
	case ePeerInfo_Port:
		peer->m_PortData.nHostPort = cMsg.Readuint16();
		break;
	case ePeerInfo_Service:
	{
		// Double pointer!
		PeerInfo_Service_Titan* pServiceInfo = (PeerInfo_Service_Titan*)&cMsg;
		peer->m_ServiceData = *pServiceInfo;
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
	CAutoMessage cMsg;

	if (pMsg == NULL || eInfoType >= ePeerInfo_TotalNum || m_nActivePeer == NO_ACTIVE_PEER) {
		return false;
	}

	Peer* peer = m_Peers.at(m_nActivePeer);

	switch (eInfoType) {
	case ePeerInfo_Age:
		cMsg.Writefloat(peer->GetCreatedAt());
		break;
	case ePeerInfo_Details:
	{
		PeerInfo_Details* details = &peer->m_DetailsData;
		cMsg.Writebool(details->bUseSkills);
		cMsg.Writebool(details->bFriendlyFire);
		cMsg.Writeuint8(details->nMPDifficulty);
		cMsg.Writefloat(details->fPlayerDiffFactor);

		if (details->Players.size() > 0) {
			// If we have players to send over, mark it as so!
			cMsg.Writebool(true);
		}

		for (auto player : details->Players) {
			cMsg.WriteString(player.sUniqueName.c_str());
			cMsg.Writeuint16(player.nPing);
		}

		// Tell them we're done printing out players
		cMsg.Writebool(false);

		cMsg.Writeuint8(details->nRunSpeed);
		cMsg.Writeuint8(details->nScoreLimit);
		cMsg.Writeuint8(details->nTimeLimit);
	}
	break;
	case ePeerInfo_Name:
		cMsg.WriteString(peer->m_NameData.sHostName.c_str());
		break;
	case ePeerInfo_Ping:
		cMsg.Writeuint16(peer->GetPing());
		break;
	case ePeerInfo_Port:
		cMsg.Writeuint16(peer->m_PortData.nHostPort);
		break;
	case ePeerInfo_Service:
	{
		// Double pointer!
		uint32 servicePointer = (uint32)&peer->m_ServiceData;
		cMsg.Writeuint32(servicePointer);
	}
		break;
	case ePeerInfo_Summary:
	{
		PeerInfo_Summary* summary = &peer->m_SummaryData;

		cMsg.WriteString(summary->sBuild.c_str());
		cMsg.WriteString(summary->sWorldName.c_str());
		cMsg.Writeuint8(summary->nCurrentPlayers);
		cMsg.Writeuint8(summary->nMaxPlayers);
		cMsg.Writebool(summary->bUsePassword);
		cMsg.Writeuint8(summary->nGameType);
		cMsg.WriteString(summary->sModName.c_str());
	}
	break;
	case ePeerInfo_Validated:
		cMsg.Writeuint8(1);
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
	SOCKET sock = NULL;

	int iResult = SetupSocket(sock, false);

	// Bad!
	if (iResult == INVALID_SOCKET) {
		return;
	}

	bool bResult;

	bResult = Connect(MASTER_SERVER, MASTER_PORT, sock);

	if (!bResult) {
		auto error = WSAGetLastError();
		ASSERT(error == 0 && "Socket Connection Error!");
		// Throw error
		return;
	}

	bResult = Query(QUERY_UPDATE_LIST, MASTER_SERVER, MASTER_PORT, sock);

	if (!bResult) {
		auto error = WSAGetLastError();
		ASSERT(error == 0 && "Socket Query Error!");
		// Throw error
		return;
	}

	std::string sServerList = Recieve(MASTER_SERVER, MASTER_PORT, sock);

	//\\basic\\secure\\TXKOAT
	//+		buffer	0x0019e894 "\\basic\\\\secure\\TXKOAT6�Z\x3l�\\final\\

	// Even php has better string handling than std! Geeeeez.
	// Easier to use c strings here.
	char* pch = strtok((char*)sServerList.c_str(), "\\");
	while (pch != NULL)
	{
		printf("%s\n", pch);

		std::string temp = pch;

		if (temp.find_first_of("TXKOAT") == 0) {
			std::string servers = temp.substr(6);


			struct ipTest {
				unsigned char ip[4];
				unsigned short port;
			};

			ipTest* test1 = (ipTest*)servers.c_str();

			unsigned short ordered = htons(test1->port);

			std::string ipBuffer;
			char buffer[32];
			//ipBuffer = test1->ip[0] << '.' << test1->ip[1] << '.' << test1->ip[2] << '.' << test1->ip[3] << ':' << ordered;

			sprintf(buffer, "%d.%d.%d.%d:%d", test1->ip[0], test1->ip[1], test1->ip[2], test1->ip[3], ordered);

			ipBuffer = buffer;

			Peer* peer = new Peer();
			peer->SetAddress(ipBuffer);

			m_mQueuedPeerMutex.lock();
			m_QueuedPeers.push_back(peer);
			m_mQueuedPeerMutex.unlock();
			//unsigned short test2 = MAKEWORD(test1->port[0], test1->port[1]);//test1->port & 0xFFFF;

			bool depro = true;
		}

		pch = strtok(NULL, "\\");
	}

	closesocket(sock);
}

void JServerDir::CheckForQueuedPeers()
{
	m_mQueuedPeerMutex.lock();
	auto queuedPeers = m_QueuedPeers;
	m_QueuedPeers.clear();
	m_mQueuedPeerMutex.unlock();

	for (Peer* peer : queuedPeers) {
		m_Peers.push_back(peer);
	}

	if (m_Peers.size() > 0) {
		m_eStatus = eStatus_Waiting;
	}
}

//
// Setup the socket with timeout
//
int JServerDir::SetupSocket(SOCKET &pSock, bool bIsUDP)
{
	int type = SOCK_STREAM;
	IPPROTO protocol = IPPROTO_TCP;

	if (bIsUDP) {
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
	}

	pSock = socket(AF_INET, type, protocol);

	if (pSock == INVALID_SOCKET) {
		int error = WSAGetLastError();
		return error;
	}

	std::string timeout = "2500";
	setsockopt(pSock, SOL_SOCKET, SO_RCVTIMEO, timeout.c_str(), sizeof(timeout.c_str()));

	return 0;
}

//
// For TCP only
//
bool JServerDir::Connect(std::string sIpAddress, unsigned short nPort, SOCKET& pSock)
{
	int iBuffer[32];

	// Setup our address
	inet_pton(AF_INET, MASTER_SERVER, (int*)iBuffer);

	sockaddr_in  saMasterAddress;
	saMasterAddress.sin_family = AF_INET;
	saMasterAddress.sin_addr.s_addr = *iBuffer;
	saMasterAddress.sin_port = htons(MASTER_PORT);

	int iResult = connect(pSock, (SOCKADDR*)&saMasterAddress, sizeof(saMasterAddress));

	if (iResult > 0) {
		return false;
	}

	return true;
}

//
// Will throw a query at the requested server
//
bool JServerDir::Query(std::string sQuery, std::string sIpAddress, unsigned short nPort, SOCKET &pSock)
{
	int iBuffer[32];

	// Setup our address
	inet_pton(AF_INET, MASTER_SERVER, (int*)iBuffer);

	sockaddr_in  saMasterAddress;
	saMasterAddress.sin_family = AF_INET;
	saMasterAddress.sin_addr.s_addr = *iBuffer;
	saMasterAddress.sin_port = htons(MASTER_PORT);
	
	// Send our query!
	int iResult = sendto(pSock, sQuery.c_str(), sizeof(sQuery.c_str()), 0, (SOCKADDR*)&saMasterAddress, sizeof(saMasterAddress));

	if (iResult == SOCKET_ERROR) {
		return false;
	}

	return true;
}

//
// Will do a blocking attempt to retrieve up to 2048 bytes from the requested server
//
std::string JServerDir::Recieve(std::string sIpAddress, unsigned short nPort, SOCKET &pSock)
{
	int iBuffer[32];
	char szBuffer[2048];
	szBuffer[0] = '\0';

	// Setup our address
	inet_pton(AF_INET, MASTER_SERVER, (int*)iBuffer);

	sockaddr_in  saMasterAddress;
	saMasterAddress.sin_family = AF_INET;
	saMasterAddress.sin_addr.s_addr = *iBuffer;
	saMasterAddress.sin_port = htons(MASTER_PORT);

	int iResult = recv(pSock, szBuffer, sizeof(szBuffer), MSG_WAITALL);

	return std::string(szBuffer);
}

void JServerDir::RequestQueueLoop()
{
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	while (true) {
		// See if we wanna kill the thread!
		if (m_bStopThread) {
			break;
		}

		Sleep(10);

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
		case eRequest_Update_List:
			QueryMasterServer();
			break;
		}

	}

	WSACleanup();
}
