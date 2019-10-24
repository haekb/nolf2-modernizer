#include "pch.h"
#include "JServerDir.h"
#include "IServerDir.h"
#include "AutoMessage.h"


JServerDir::JServerDir(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule)
{
	m_bClientSide = bClientSide;
	m_pLTCSBase = &ltCSBase;
	m_hResourceModule = hResourceModule;
	m_nActivePeer = -1;
}

JServerDir::~JServerDir()
{

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
	return "Hello world!";
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

		std::vector<PeerInfo_PlayerDetails>::iterator it = details->Players.begin();

		for (it = details->Players.begin(); it != details->Players.end(); it++) {
			cMsg.WriteString(it->sUniqueName.c_str());
			cMsg.Writeuint16(it->nPing);
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
