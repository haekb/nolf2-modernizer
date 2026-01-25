#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <regex>
#include <chrono>

#include "NetDefs.h"
#include "Peer.h"
#include "JServerDir.h"
#include "IServerDir_Titan.h"

extern JServerDir* g_pJServerDir;

int gameTypeStringToInt(std::string sGameType)
{
	if (sGameType.compare("Cooperative") == 0) {
		return eGameTypeCooperative;
	}
	else if (sGameType.compare("DeathMatch") == 0) {
		return eGameTypeDeathmatch;
	}
	else if (sGameType.compare("DoomsDay") == 0) {
		return eGameTypeDoomsDay;
	}
	else if (sGameType.compare("TeamDeathMatch") == 0) {
		return eGameTypeTeamDeathmatch;
	}

	// Error!
	return -1;
}

std::string gameTypeIntToString(int nGameType)
{
	switch (nGameType) {
	case eGameTypeCooperative:
		return "Cooperative";
	case eGameTypeDeathmatch:
		return "DeathMatch";
	case eGameTypeDoomsDay:
		return "DoomsDay";
	case eGameTypeTeamDeathmatch:
		return "TeamDeathMatch";
	case eGameTypeSingle: // ??
		return "SinglePlayer";
	}

	// Error!
	return "N/A";
}

std::vector<std::string> splitByCharacter(std::string input, char character)
{
	std::stringstream test(input);
	std::string segment;
	std::vector<std::string> seglist;

	while (std::getline(test, segment, character))
	{
		seglist.push_back(segment);
	}

	return seglist;
}

//
// Highly specialized for server query results, will fix later
//
std::map<std::string, std::string> splitResultsToMap(std::string input)
{
	std::map<std::string, std::string> splitMap;
	std::string pattern = "\\\\([\\d\\w\\.\\s]*)\\\\([\\d\\w\\.\\s]*)";
	std::regex commandRegex(pattern);
	std::smatch match;

	std::string searchString = input;

	while (std::regex_search(searchString, match, commandRegex)) {

		splitMap.insert({ match[1], match[2] });
		searchString = match.suffix().str();
	}
	
	return splitMap;
}

std::string encodeGameInfoToString(Peer* peer)
{
	if (!peer->HasSummaryData() || !peer->HasServiceData() || !peer->HasPortData())
	{
		return "";
	}

	// TODO: Move this to outside the function, and make this function take in the map.
	std::map<std::string, std::string> splitMap;

	std::string gameName = g_pJServerDir->GetGameName();

	std::transform(gameName.begin(), gameName.end(), gameName.begin(), ::tolower);
	//splitMap.insert({ "hostip"  , "192.168.1.1" });//peer->GetAddress() });

	// Basic
	splitMap.insert({ "gamename", gameName });
	splitMap.insert({ "gamever" , g_pJServerDir->GetVersion()  }); //"1.0.0.3" });
	splitMap.insert({ "location", "0"});

	// Info
	splitMap.insert({ "hostname", peer->m_ServiceData.m_sHostName });
	splitMap.insert({ "hostport", std::to_string(peer->m_PortData.nHostPort) });
	splitMap.insert({ "mapname", peer->m_ServiceData.m_sCurWorld });
	splitMap.insert({ "gametype", gameTypeIntToString(peer->m_SummaryData.nGameType) });
	splitMap.insert({ "numplayers", std::to_string(peer->m_SummaryData.nCurrentPlayers) });
	splitMap.insert({ "maxplayers", std::to_string(peer->m_ServiceData.m_nMaxNumPlayers) });

	// ?
	splitMap.insert({ "gamestate", peer->IsShuttingDown() ? "exiting" : "openplaying" });

	// Rules
	splitMap.insert({ "gamemode", peer->IsShuttingDown() ? "exiting" : gameTypeIntToString(peer->m_SummaryData.nGameType) });
	splitMap.insert({ "fraglimit", std::to_string(peer->m_ServiceData.m_nScoreLimit) });
	splitMap.insert({ "timelimit", std::to_string(peer->m_ServiceData.m_nTimeLimit) });
	splitMap.insert({ "options", peer->m_ServiceData.m_sServerOptions }); // I think this is right?

	splitMap.insert({ "password", peer->m_SummaryData.bUsePassword ? "1" : "0" });

	// Players
	int nPlayerIndex = 0;
	for (PeerInfo_Service_Titan::Player playerObj : peer->m_ServiceData.m_PlayerList) {
		std::string sPlayerIndex = std::to_string(nPlayerIndex);

		std::string player = "player_" + sPlayerIndex;
		std::string score = "score_" + sPlayerIndex;
		std::string ping = "ping_" + sPlayerIndex;
		
		splitMap.insert({ player, playerObj.m_sName });
		splitMap.insert({ score, std::to_string(playerObj.m_nScore) });
		splitMap.insert({ ping, std::to_string(playerObj.m_nPing) });

		nPlayerIndex++;
	}

	std::string sGameInfo = "";

	for (auto map : splitMap) {
		sGameInfo += "\\" + map.first + "\\" + map.second;
	}

	sGameInfo += "\\final\\queryid\\";

	return sGameInfo;
}

long long getTimestamp()
{
	return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

long long getTimestampInMs()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::string getHeartbeat(int &iQueryNum, int iPort, bool bStateChanged = false)
{
	std::string heartbeat = "\\heartbeat\\" + std::to_string(iPort) + "\\gamename\\nolf2\\";

	if (bStateChanged) {
		heartbeat += "statechanged\\\\";
	}

	heartbeat += "final\\\\queryid\\" + std::to_string(++iQueryNum) + ".1";

	return heartbeat;
}

std::string handleValidationQuery(std::string challengeResponse) {
	auto splitVals = splitByCharacter(challengeResponse, '\\');
	std::string challenge = "";

	// Find secure, right after that is the challenge string
	for (auto i = 0; i < splitVals.size(); i++) {
		if (splitVals[i] == "secure" && i+1 < splitVals.size()) {
			challenge = splitVals[i + 1];
			break;
		}
	}

	if (challenge.empty()) {
		return "";
	}

	unsigned char* destValidate = gsseckey(nullptr, (unsigned char*)challenge.c_str(), (unsigned char*)GAMESPY_PW, 0);
	if (!destValidate) {
		return "";
	}

	std::string query = "\\validate\\";
	query += (char*)destValidate;
	return query;
}