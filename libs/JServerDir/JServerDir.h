#pragma once
#include "pch.h"

#define SERVERDIR_EXPORTS

#include "IServerDir.h"
#include "IServerDir_Titan.h"
#include "iltcsbase.h"


#define FAKE_CD_KEY "ABC1-EFG2-IJK3-LMN4-5678"
#define LOCAL_PEER "_LOCAL_PEER"
#define NO_ACTIVE_PEER -1

struct PeerInfo_Name {
	std::string sHostName;
};

struct PeerInfo_Summary {
	std::string sBuild;
	std::string sWorldName;
	uint8 nCurrentPlayers;
	uint8 nMaxPlayers;
	bool bUsePassword;
	uint8 nGameType;
	std::string sModName;
};

struct PeerInfo_PlayerDetails {
	std::string sUniqueName;
	uint16 nPing;
};

struct PeerInfo_Details {
	bool bUseSkills;
	bool bFriendlyFire;
	uint8 nMPDifficulty;
	float fPlayerDiffFactor;
	std::vector<PeerInfo_PlayerDetails> Players; // Reference summaryData::nCurrentPlayers?
	uint8 nRunSpeed;
	uint8 nScoreLimit;
	uint8 nTimeLimit;
};

struct PeerInfo_Port {
	uint16 nHostPort;
};

// Nice and complete struct!
struct PeerData {
	std::string sPeerAddress;
	uint16 nPing;
	LTFLOAT fCreatedAt;
	bool bIsDataSet;

	// Data
	PeerInfo_Name nameData;
	PeerInfo_Summary summaryData;
	PeerInfo_Details detailsData;
	PeerInfo_Port portData;
	PeerInfo_Service_Titan serviceData;
};


class JServerDir :
	public IServerDirectory
{
protected:
	ILTCSBase* m_pLTCSBase;
	HMODULE m_hResourceModule;
	bool m_bClientSide;

	std::string m_sGameName;
	std::string m_sVersion;
	std::string m_sRegion;

	StartupInfo_Titan m_StartupInfo;

	// Maybe just generate this on the fly for the client?
	//TPeerList m_PeerList;

	// All I see is pears
	std::vector<PeerData> m_Peers;

	int m_nActivePeer;

	EStatus m_eStatus;

public:

	JServerDir(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule);
	~JServerDir();

	//////////////////////////////////////////////////////////////////////////////
	// Request handling

	// Add a request to the end of the queue
	// Returns false if unable to add the request to the queue
	// Note : A return value of true does NOT imply that the request completed
	// successfully.
	virtual bool QueueRequest(ERequest eNewRequest) = 0;
	// Add a list of requests to the queue
	// Returns false if any of the requests could not be added.  (And does not
	// add any of them in that case.)
	virtual bool QueueRequestList(const TRequestList& cNewRequests) = 0;
	// Retrieve the list of waiting requests.  
	// The first entry is the entry which is currently being processed.
	virtual TRequestList GetWaitingRequestList() const = 0;
	// Clear the request list
	// Note : Request list processing must be paused to clear the request list
	// Returns false if the request list is currently being processed.
	virtual bool ClearRequestList() = 0;
	// Pause processing, process the given request, return the result,
	// and go back to the previous state.
	// Returns the result of the request
	virtual ERequestResult ProcessRequest(ERequest eNewRequest, uint32 nTimeout) = 0;

	// Pauses the request list processing
	// Note : This will cancel the active request, and schedule it for 
	// re-processing when processing is resumed.
	virtual bool PauseRequestList() = 0;
	// Process (or continue processing) the request list
	virtual bool ProcessRequestList() = 0;

	// Wait until the next request is completed and return the result
	virtual ERequestResult BlockOnActiveRequest(uint32 nTimeout) = 0;
	// Wait until the next request matching eBlockRequest is completed and 
	// return its result
	// Note : Returns eRequestResult_Aborted if an earlier request fails
	virtual ERequestResult BlockOnRequest(ERequest eBlockRequest, uint32 nTimeout) = 0;
	// Wait until the next request matching one of the entries in 
	// eBlockRequestList is completed and return its result
	// Note : Returns eRequestResult_Aborted if an earlier request fails
	virtual ERequestResult BlockOnRequestList(const TRequestList& cBlockRequestList, uint32 nTimeout) = 0;
	// Wait until we go out of the processing state
	virtual ERequestResult BlockOnProcessing(uint32 nTimeout) = 0;

	// Is this request in request list?
	virtual bool IsRequestPending(ERequest ePendingRequest) const = 0;

	// A list of servers
	typedef std::vector<std::string> TPeerList;
	// Returns the most recently successful request
	virtual ERequest GetLastSuccessfulRequest() const = 0;
	// Returns the most recently failed request
	virtual ERequest GetLastErrorRequest() const = 0;
	// Returns the currently active request
	virtual ERequest GetActiveRequest() const = 0;

	// Get the most recently processed request
	virtual ERequest GetLastRequest() const = 0;
	// Get the result of the most recently processed result
	virtual ERequestResult GetLastRequestResult() const = 0;
	// Get the string associated with the most recently processed result
	virtual const char* GetLastRequestResultString() const = 0;

	//////////////////////////////////////////////////////////////////////////////
	// Status

	// Get the current status
	virtual EStatus GetCurStatus() const;
	// Get the descriptive text associated with the current status
	virtual const char* GetCurStatusString() const;

	//////////////////////////////////////////////////////////////////////////////
	// Startup - service specific.

	virtual void SetStartupInfo(ILTMessage_Read& cMsg);
	virtual void GetStartupInfo(ILTMessage_Write& cMsg);

	//////////////////////////////////////////////////////////////////////////////
	// Game name

	virtual void SetGameName(const char* pName);
	virtual const char* GetGameName() const;

	//////////////////////////////////////////////////////////////////////////////
	// CD Keys

	// Set the current CD key
	virtual bool SetCDKey(const char* pKey);
	// Get the current CD key
	virtual bool GetCDKey(std::string* pKey);
	// Is the current CD key valid?
	// Note : This will return false until a eRequest_Validate_CDKey request has been processed
	virtual bool IsCDKeyValid() const;

	//////////////////////////////////////////////////////////////////////////////
	// Game Version

	// Set the current version
	virtual void SetVersion(const char* pVersion);
	// Set the current region
	virtual void SetRegion(const char* pRegion);
	// Is the current version valid?
	// Note : Returns false if eRequest_Validate_Version has not been processed
	virtual bool IsVersionValid() const;
	// Is the current version the newest version?
	// Note : Returns false if eRequest_Validate_Version has not been processed
	virtual bool IsVersionNewest() const;
	// Is a patch available?
	// Note : Returns false if eRequest_Validate_Version has not been processed
	virtual bool IsPatchAvailable() const;

	//////////////////////////////////////////////////////////////////////////////
	// Message of the Day

	// Is the MOTD "new"?
	// Note : Returns false if eRequest_MOTD has not been processed
	virtual bool IsMOTDNew(EMOTD eMOTD) const;
	// Get the current MOTD
	virtual char const* GetMOTD(EMOTD eMOTD) const;

	//////////////////////////////////////////////////////////////////////////////
	// Active peer info

	// Sets the active peer address and port
	// Note : Use NULL to indicate the local machine
	// Returns false if there was some problem
	virtual bool SetActivePeer(const char* pAddr);
	// Get the currently selected active peer
	// Returns false if there was some problem  (e.g. a null parameter)
	virtual bool GetActivePeer(std::string* pAddr, bool* pLocal) const;
	// Remove the active peer from the peer list
	// The active peer will be set to the local machine
	// Returns false if the peer is the local machine
	virtual bool RemoveActivePeer();

	// Change the active peer info
	virtual bool SetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Read& cMsg);
	// Has the active peer info been queried from the directory server?
	// Returns true if the required information has been queried
	virtual bool HasActivePeerInfo(EPeerInfo eInfoType) const;
	// Get the current active server info
	// Returns false if that information has not been queried for the active peer,
	// or if pMsg is null
	virtual bool GetActivePeerInfo(EPeerInfo eInfoType, ILTMessage_Write* pMsg) const;

	//////////////////////////////////////////////////////////////////////////////
	// Peer listing

	// Get the current list of known peers
	// Note : This list will be empty until a eRequest_Update_List request has been
	// successfully processed, or SetActivePeer has been called with a non-local peer
	virtual TPeerList GetPeerList() const = 0;
	// Clear the current list of known peers
	virtual void ClearPeerList() = 0;

	//////////////////////////////////////////////////////////////////////////////
	// Net message handling

	// Handle an incoming net message
	// Returns false if the message was not recognized
	// Note : Remove all external headers before calling this function
	virtual bool HandleNetMessage(ILTMessage_Read& cMsg, const char* pSender, uint16 nPort) = 0;
	// Set the header which will be appended to the beginning of all outgoing messages
	virtual bool SetNetHeader(ILTMessage_Read& cMsg) = 0;
};

