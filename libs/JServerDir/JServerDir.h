#pragma once
#include "pch.h"

#define SERVERDIR_EXPORTS

// Uncomment if you want it to work with NOLF2 vanilla
#define _DROPIN

#include "IServerDir.h"
#include "IServerDir_Titan.h"
#include "iltcsbase.h"
#include "Peer.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stl_vector.h>


#define FAKE_CD_KEY "ABC1-EFG2-IJK3-LMN4-5678"
#define LOCAL_PEER "_LOCAL_PEER"
#define NO_ACTIVE_PEER -1

// TODO: Throw this in a ini file!
#define MASTER_SERVER "65.112.87.186"
#define MASTER_PORT 28900

#define QUERY_UPDATE_LIST "\\gamename\\nolf2\\gamever\\1.3\\location\\0\\validate\\g3Fo6x\\final\\"
//#define QUERY_UPDATE_LIST "\\list\\gamename\\nolf2\\final\\"

struct Job {
	IServerDirectory::ERequest eRequestType;
};

class JServerDir :
	public IServerDirectory
{
public:

	JServerDir(bool bClientSide, ILTCSBase& ltCSBase, HMODULE hResourceModule);
	~JServerDir();

	//////////////////////////////////////////////////////////////////////////////
	// Request handling

	// Add a request to the end of the queue
	// Returns false if unable to add the request to the queue
	// Note : A return value of true does NOT imply that the request completed
	// successfully.
	virtual bool QueueRequest(ERequest eNewRequest);
	// Add a list of requests to the queue
	// Returns false if any of the requests could not be added.  (And does not
	// add any of them in that case.)
	virtual bool QueueRequestList(const TRequestList& cNewRequests);
	// Retrieve the list of waiting requests.  
	// The first entry is the entry which is currently being processed.
	virtual TRequestList GetWaitingRequestList() const;
	// Clear the request list
	// Note : Request list processing must be paused to clear the request list
	// Returns false if the request list is currently being processed.
	virtual bool ClearRequestList();
	// Pause processing, process the given request, return the result,
	// and go back to the previous state.
	// Returns the result of the request
	virtual ERequestResult ProcessRequest(ERequest eNewRequest, uint32 nTimeout);

	// Pauses the request list processing
	// Note : This will cancel the active request, and schedule it for 
	// re-processing when processing is resumed.
	virtual bool PauseRequestList();
	// Process (or continue processing) the request list
	virtual bool ProcessRequestList();

	// Wait until the next request is completed and return the result
	virtual ERequestResult BlockOnActiveRequest(uint32 nTimeout);
	// Wait until the next request matching eBlockRequest is completed and 
	// return its result
	// Note : Returns eRequestResult_Aborted if an earlier request fails
	virtual ERequestResult BlockOnRequest(ERequest eBlockRequest, uint32 nTimeout);
	// Wait until the next request matching one of the entries in 
	// eBlockRequestList is completed and return its result
	// Note : Returns eRequestResult_Aborted if an earlier request fails
	virtual ERequestResult BlockOnRequestList(const TRequestList& cBlockRequestList, uint32 nTimeout);
	// Wait until we go out of the processing state
	virtual ERequestResult BlockOnProcessing(uint32 nTimeout);

	// Is this request in request list?
	virtual bool IsRequestPending(ERequest ePendingRequest) const;

	// A list of servers
	typedef std::vector<std::string> TPeerList;

	// Returns the most recently successful request
	virtual ERequest GetLastSuccessfulRequest() const;
	// Returns the most recently failed request
	virtual ERequest GetLastErrorRequest() const;
	// Returns the currently active request
	virtual ERequest GetActiveRequest() const;

	// Get the most recently processed request
	virtual ERequest GetLastRequest() const;
	// Get the result of the most recently processed result
	virtual ERequestResult GetLastRequestResult() const;
	// Get the string associated with the most recently processed result
	virtual const char* GetLastRequestResultString() const;

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
	virtual TPeerList GetPeerList() const;
	// Clear the current list of known peers
	virtual void ClearPeerList();

	//////////////////////////////////////////////////////////////////////////////
	// Net message handling

	// Handle an incoming net message
	// Returns false if the message was not recognized
	// Note : Remove all external headers before calling this function
	virtual bool HandleNetMessage(ILTMessage_Read& cMsg, const char* pSender, uint16 nPort);
	// Set the header which will be appended to the beginning of all outgoing messages
	virtual bool SetNetHeader(ILTMessage_Read& cMsg);

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
		std::vector<Peer*> m_Peers;

		int m_nActivePeer;

		EStatus m_eStatus;

		bool m_bIsRequestQueueRunning;

		std::thread m_tRequestQueue;

		// 
		void Update();
		void QueryMasterServer();
		void CheckForQueuedPeers();

		int SetupSocket(SOCKET &pSock, bool bIsUDP);
		bool Connect(std::string sIpAddress, unsigned short nPort, SOCKET& pSock);
		bool Query(std::string sQuery, std::string sIpAddress, unsigned short nPort, SOCKET &pSock);
		std::string Recieve(std::string sIpAddress, unsigned short nPort, SOCKET &pSock);

		// Thread Stuff
		std::atomic_bool m_bStopThread;
		std::mutex m_mJobMutex;
		std::mutex m_mQueuedPeerMutex;
		std::vector<Job> m_vJobs;
		// Weird, but to avoid a lot of mutexing, this is the prep vector that will eventually be merged into Peers
		std::vector<Peer*> m_QueuedPeers;

		void RequestQueueLoop();

};

