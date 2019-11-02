#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include "IServerDir_Titan.h"

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

class Peer
{
public:

	Peer();
	~Peer();

	inline void SetAddress(std::string sPeerAddress) {
		m_sPeerAddress = sPeerAddress;
	}

	inline void SetPing(uint16 nPing) {
		m_nPing = nPing;
	}

	inline void SetCreatedAt(LTFLOAT fCreatedAt) {
		m_fCreatedAt = fCreatedAt;
	}

	inline std::string GetAddress() { return m_sPeerAddress; }
	inline uint16 GetPing() { return m_nPing; }
	inline LTFLOAT GetCreatedAt() { return m_fCreatedAt; }

	inline bool HasNameData() { return m_bHasNameData; }
	inline bool HasSummaryData() { return m_bHasSummaryData; }
	inline bool HasDetailsData() { return m_bHasDetailsData; }
	inline bool HasPortData() { return m_bHasPortData; }
	inline bool HasServiceData() { return m_bHasServiceData; }

	inline void SetHasNameData(bool bVal) { m_bHasNameData = bVal; };
	inline void SetHasSummaryData(bool bVal) { m_bHasSummaryData = bVal; };
	inline void SetHasDetailsData(bool bVal) { m_bHasDetailsData = bVal; };
	inline void SetHasPortData(bool bVal) { m_bHasPortData = bVal; };
	inline void SetHasServiceData(bool bVal) { m_bHasServiceData = bVal; };

	inline bool IsValidated() { return m_bIsValidated; }

	// Data -- Here because i'm lazy
	PeerInfo_Name m_NameData;
	PeerInfo_Summary m_SummaryData;
	PeerInfo_Details m_DetailsData;
	PeerInfo_Port m_PortData;
	PeerInfo_Service_Titan m_ServiceData;

protected:
	std::string m_sPeerAddress;
	uint16 m_nPing;
	LTFLOAT m_fCreatedAt;

	// Is the data set?
	bool m_bHasNameData;
	bool m_bHasSummaryData;
	bool m_bHasDetailsData;
	bool m_bHasPortData;
	bool m_bHasServiceData;
	bool m_bIsValidated;



private:

};

