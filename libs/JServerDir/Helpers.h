#pragma once
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <regex>

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
	std::string gameInfo = "\\gamename\\nolf2\\gamever\\1.0.0.3\\gamemode\\openplaying\\gametype\\DoomsDay\\hostip\\172.31.41.243\\hostname\\Jake DM\\hostport\\27888\\mapname\\DD_06\\maxplayers\\16\\numplayers\\0\\fraglimit\\0\\options\\\\password\\0\\timelimit\\20\\frags_0\\0\\frags_1\\0\\frags_2\\0\\ping_0\\334\\ping_1\\24129\\ping_2\\1287\\player_0\\A DEAD BABY\\player_1\\Ya Basta\\player_2\\Ya Basta1\\final\\\\queryid\\74383.1";

	if (!peer->HasSummaryData() || !peer->HasServiceData() || !peer->HasPortData())
	{
		return "";
	}

	// TODO: Move this to outside the function, and make this function take in the map.
	std::map<std::string, std::string> splitMap;

	std::string gameName = g_pJServerDir->GetGameName();

	std::transform(gameName.begin(), gameName.end(), gameName.begin(), ::tolower);

	splitMap.insert({ "gamename", gameName });
	splitMap.insert({ "gamever" , g_pJServerDir->GetVersion()  }); //"1.0.0.3" });
	splitMap.insert({ "gamemode", peer->IsShuttingDown() ? "exiting" : "openplaying" });

	splitMap.insert({ "gametype", gameTypeIntToString(peer->m_SummaryData.nGameType) });
	splitMap.insert({ "hostip"  , "192.168.1.1" });//peer->GetAddress() });
	splitMap.insert({ "hostname", peer->m_ServiceData.m_sHostName });
	splitMap.insert({ "hostport", std::to_string(peer->m_PortData.nHostPort) });
	splitMap.insert({ "mapname", peer->m_ServiceData.m_sCurWorld });
	splitMap.insert({ "maxplayers", std::to_string(peer->m_ServiceData.m_nMaxNumPlayers) });
	splitMap.insert({ "numplayers", std::to_string(peer->m_SummaryData.nCurrentPlayers) });
	splitMap.insert({ "fraglimit", std::to_string(peer->m_ServiceData.m_nScoreLimit) });
	splitMap.insert({ "options", peer->m_ServiceData.m_sServerOptions }); // I think this is right?
	splitMap.insert({ "password", peer->m_SummaryData.bUsePassword ? "1" : "0" });
	splitMap.insert({ "timelimit", std::to_string(peer->m_ServiceData.m_nTimeLimit) });

	int nPlayerIndex = 0;
	for (PeerInfo_Service_Titan::Player playerObj : peer->m_ServiceData.m_PlayerList) {
		std::string sPlayerIndex = std::to_string(nPlayerIndex);

		std::string frag = "frag_" + sPlayerIndex;
		std::string ping = "ping_" + sPlayerIndex;
		std::string player = "player_" + sPlayerIndex;

		splitMap.insert({ frag, std::to_string(playerObj.m_nScore) });
		splitMap.insert({ ping, std::to_string(playerObj.m_nPing) });
		splitMap.insert({ player, playerObj.m_sName });

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