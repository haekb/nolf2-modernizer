#include "pch.h"
#include "JServerDir.h"


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
	m_szGameName = pName;
}

const char* JServerDir::GetGameName() const
{
	return m_szGameName.c_str();
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
	m_szVersion = pVersion;
}

// Set the current region
void JServerDir::SetRegion(const char* pRegion)
{
	m_szRegion = pRegion;
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

	PeerData peer;
	peer.peerAddress = *pAddr;
	peer.bIsDataSet = false;

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

	PeerData peer = m_Peers.at(m_nActivePeer);
	std::string activePeer = peer.peerAddress;

	if (activePeer == LOCAL_PEER) {
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
	PeerData peer = m_Peers.at(m_nActivePeer);

	if (peer.peerAddress.compare(LOCAL_PEER)) {
		return false;
	}

	m_Peers.erase(m_Peers.begin() + m_nActivePeer);

	m_nActivePeer = NO_ACTIVE_PEER;

	return true;
}

// Change the active peer info
bool JServerDir::SetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Read& cMsg)
{

}
// Has the active peer info been queried from the directory server?
// Returns true if the required information has been queried
bool JServerDir::HasActivePeerInfo(EPeerInfo eInfoType) const
{

}
// Get the current active server info
// Returns false if that information has not been queried for the active peer,
// or if pMsg is null
bool JServerDir::GetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Write* pMsg) const
{

}