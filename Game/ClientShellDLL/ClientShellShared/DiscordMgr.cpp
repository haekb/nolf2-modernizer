#include "stdafx.h"
#include "DiscordMgr.h"
#include <iostream>
#include <SDL.h>
#include "MissionMgr.h"

DiscordMgr* g_pDiscordMgr;
extern CMissionMgr* g_pMissionMgr;
extern ILTClient* g_pLTClient;

void LogProblemsFunction(discord::LogLevel level, std::string message)
{
	SDL_Log("[Discord] %d - %s", level, message);
}

//
// Warning, prototyping in here!
//

DiscordMgr::DiscordMgr()
{
	//g_pDiscordMgr = this;
}

DiscordMgr::~DiscordMgr()
{
}

void DiscordMgr::Init()
{
	SDL_Log("Setting up Discord Game SDK");
	/*
	Grab that Client ID from earlier
	Discord.CreateFlags.Default will require Discord to be running for the game to work
	If Discord is not running, it will:
	1. Close your game
	2. Open Discord
	3. Attempt to re-open your game
	Step 3 will fail when running directly from the Unity editor
	Therefore, always keep Discord running during tests, or use Discord.CreateFlags.NoRequireDiscord
	*/
	
	auto result = discord::Core::Create(DISCORD_CLIENT_ID, DiscordCreateFlags_Default, &m_pCore);
	discord::Activity activity{};
	activity.SetState("In Menu");
	activity.SetDetails("Doing non-essential stuff");
	activity.GetAssets().SetLargeImage("default");
	//activity.GetAssets().SetSmallImage("default");

	m_pCore->ActivityManager().UpdateActivity(activity, [](discord::Result result) {

	});

	m_pCore->SetLogHook(discord::LogLevel::Debug, LogProblemsFunction);

	m_sState.core.reset(m_pCore);

	// Setup a OnJoin callback
	{
		m_sState.core->ActivityManager().OnActivityJoin.Connect(
				[](const char* secret) 
		{ 
			SDL_Log("Joining %s", secret);

			g_pDiscordMgr->m_sState.core->LobbyManager().ConnectLobbyWithActivitySecret(secret, 
				[](discord::Result result, discord::Lobby const& lobby)
			{

				SDL_Log("Result %d", result);



			});
		
		});

	}



	SDL_Log("Discord Game SDK setup!");
}

void DiscordMgr::Update()
{
	m_sState.core->RunCallbacks();
}

bool DiscordMgr::CreateLobby(StartGameRequest* pGameRequest)
{
	ServerGameOptions* pGameOptions = (ServerGameOptions*)pGameRequest->m_pGameInfo;

	discord::LobbyTransaction lobby{};

	// Get our ip address and port...
	char sBuf[32];
	int  nBufSize = 30;
	WORD wPort = 0;
	auto result2222 = g_pLTClient->GetTcpIpAddress(sBuf, nBufSize, wPort);

	uint8 nServerAddr[4];
	uint16 nServerPort;
	auto ipresult = g_pLTClient->GetServerIPAddress(nServerAddr, &nServerPort);

	m_sState.core->LobbyManager().GetLobbyCreateTransaction(&lobby);
	lobby.SetCapacity(pGameOptions->GetMaxPlayers());
	lobby.SetType(discord::LobbyType::Public);

	lobby.SetMetadata("ip", pGameRequest->m_TCPAddress);
	lobby.SetMetadata("port", std::to_string(pGameOptions->m_nPort).c_str());

	std::string sessionName = pGameOptions->GetSessionName();
	auto timelimit = pGameOptions->GetDeathmatch().m_nTimeLimit;
	auto size = pGameOptions->GetMaxPlayers();
	

	m_sState.core->LobbyManager().CreateLobby(
		lobby,
		[sessionName, size](discord::Result result, discord::Lobby const& lobby) {
			if (result == discord::Result::Ok) {
				SDL_Log("Created lobby");

				std::array<uint8_t, 234> data{};
				g_pDiscordMgr->m_sState.core->LobbyManager().SendLobbyMessage(
					lobby.GetId(),
					reinterpret_cast<uint8_t*>(data.data()),
					data.size(),
					[](discord::Result result) {

					SDL_Log("Sent Message. Result: %d", result);
				});
			}
			else {
				SDL_Log("Failed to create lobby");
				return;
			}

			discord::LobbySearchQuery query{};
			g_pDiscordMgr->m_sState.core->LobbyManager().GetSearchQuery(&query);
			query.Limit(1);
			g_pDiscordMgr->m_sState.core->LobbyManager().Search(query, [](discord::Result result) {
				if (result == discord::Result::Ok) {
					std::int32_t lobbyCount{};
					g_pDiscordMgr->m_sState.core->LobbyManager().LobbyCount(&lobbyCount);
					SDL_Log("Lobby search succeeded with %d lobbies", lobbyCount);
					for (auto i = 0; i < lobbyCount; ++i) {
						discord::LobbyId lobbyId{};
						g_pDiscordMgr->m_sState.core->LobbyManager().GetLobbyId(i, &lobbyId);
						std::cout << "  " << lobbyId << "\n";
					}
				}
				else {
					SDL_Log("Lobby search failed. (err %d)", result);
				}
			});


		
			

			discord::Activity activity{};
			discord::Timestamp timestamp = 0;

			int nCurMission = g_pMissionMgr->GetCurrentMission();
			MISSION* pMission = g_pMissionButeMgr->GetMission(nCurMission);


			std::string missionName;
			std::string levelName;


			if (pMission->nNameId > 0)
				missionName = LoadTempString(pMission->nNameId);
			else
				missionName = pMission->sName;

			int nCurLevel = g_pMissionMgr->GetCurrentLevel();
			levelName = LoadTempString(pMission->aLevels[nCurLevel].nNameId);

			std::string altMissionName = LoadTempString(IDS_CUSTOM_LEVEL);
			// Split the worldname up into parts so we can get the load string.
			char const* pszWorldName = g_pMissionMgr->GetCurrentWorldName();
			char szWorldTitle[MAX_PATH] = "";
			_splitpath(pszWorldName, NULL, NULL, szWorldTitle, NULL);
			std::string altLevelName = szWorldTitle;



			auto level = "Playing " + missionName;

			activity.SetState("Playing Deathmatch");
			activity.SetDetails(level.c_str());
			
			
			discord::PartySize party;

			activity.GetParty().SetId("ahhhh");

			activity.GetParty().GetSize().SetCurrentSize(1);
			activity.GetParty().GetSize().SetMaxSize(size);

			activity.GetSecrets().SetJoin("er2kl4l52eledsjpasdfp4346"); // needed for ask to join to show up
			//activity.GetSecrets().SetMatch("match");
			// Map
			activity.GetAssets().SetLargeImage("dm_05");
			activity.GetAssets().SetLargeText(level.c_str());
			activity.SetInstance(true);

			g_pDiscordMgr->m_sState.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {

			});
		}
	);

	return true;
}

bool DiscordMgr::JoinLobby()
{
	return false;
}
