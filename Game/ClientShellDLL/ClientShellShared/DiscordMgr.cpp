#include "stdafx.h"
#include "DiscordMgr.h"
#include <iostream>
#include <SDL.h>
#include "GameClientShell.h"
#include "MissionMgr.h"
#include "ClientMultiplayerMgr.h"
#include "helpers.h"

DiscordMgr* g_pDiscordMgr;
extern CGameClientShell* g_pGameClientShell;
extern CMissionMgr* g_pMissionMgr;
extern ILTClient* g_pLTClient;
extern ClientMultiplayerMgr* g_pClientMultiplayerMgr;
extern SDL_Window* g_SDLWindow;

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
	m_pCurrentLobby = NULL;
	m_pCore = NULL;

	ClearDiscordActivity(m_sCachedActivityData);
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




	m_pCore->SetLogHook(discord::LogLevel::Debug, LogProblemsFunction);

	m_sState.core.reset(m_pCore);

	UpdateActivity();

	// Setup a OnJoin callback
	{
		m_sState.core->ActivityManager().OnActivityJoin.Connect(
				[](const char* secret) 
		{ 
			SDL_Log("Joining %s", secret);

			g_pDiscordMgr->m_sState.core->LobbyManager().ConnectLobbyWithActivitySecret(secret, 
				[](discord::Result result, discord::Lobby const& lobby)
			{
				if (result == discord::Result::Ok) {
					g_pDiscordMgr->JoinLobby(lobby);
				}
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
	// Handle the double pointer nonsense.
	void* data = *((void**)pGameRequest->m_pGameInfo);
	ServerGameOptions* pGameOptions = (ServerGameOptions*)data;
	  
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

	lobby.SetMetadata("ip", sBuf);
	lobby.SetMetadata("port", std::to_string(wPort).c_str());

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

			// Save the lobby
			g_pDiscordMgr->m_InternalCurrentLobby = (discord::Lobby)lobby;
			g_pDiscordMgr->m_pCurrentLobby = &g_pDiscordMgr->m_InternalCurrentLobby;
		}
	);

	return true;
}

bool DiscordMgr::JoinLobby(discord::Lobby const& lobby)
{
	char ipAddress[4096];

	memset(ipAddress, '\0', sizeof(ipAddress));

	auto result = g_pDiscordMgr->m_sState.core->LobbyManager().GetLobbyMetadataValue(lobby.GetId(), "ip", ipAddress);

	SDL_Log("Meta Data Result %d", result);
	SDL_Log("IP: %s", ipAddress);

	bool bOk = g_pClientMultiplayerMgr->SetupClient(ipAddress, "Jake DM", 0);

	// Join the server!
	bOk = bOk && g_pMissionMgr->StartGameAsClient();

	if (bOk) {
		g_pDiscordMgr->m_InternalCurrentLobby = (discord::Lobby)lobby;
		g_pDiscordMgr->m_pCurrentLobby = &g_pDiscordMgr->m_InternalCurrentLobby;

		// Small hack to grab focus so loading screen thread doesn't cause crash.

		// Small Hack Start
		HCONSOLEVAR hVar = g_pLTClient->GetConsoleVar("Windowed");
		bool bFocusWindow = false;
		if (hVar)
		{
			float fVal = g_pLTClient->GetVarValueFloat(hVar);
			if (fVal == 1.0f)
			{
				bFocusWindow = true;
			}
		}

		if (bFocusWindow) {
			SDL_RaiseWindow(g_SDLWindow);
		}
		// Small Hack End

		UpdateActivity();
	}

	return bOk;
}

bool DiscordMgr::LeaveLobby()
{
	m_pCurrentLobby = NULL;
	UpdateActivity();
	return true;
}

// Overall "Sync"
// It's slow, I need to move to a more dynamic solution.
void DiscordMgr::UpdateActivity()
{
	discord::Activity activity{};

	// Bit of duplicate data, but easy out. Menus never change!
	if (m_sCachedActivityData.inMenu && !g_pGameClientShell->GetPlayerMgr()->IsPlayerInWorld()) {
		return;
	}

	DiscordActivityData activityData;

	activityData.state = "In Menu";
	activityData.details = "Doing non-essential stuff";
	activityData.largeImageName = "default";
	activityData.largeImageText = "";
	activityData.currentPlayers = 1;
	activityData.maxPlayers = 1;
	activityData.lobbyId = "N/A";
	activityData.inMenu = !g_pGameClientShell->GetPlayerMgr()->IsPlayerInWorld();

	if (activityData.inMenu) {
		activity.SetState(activityData.state.c_str());
		activity.SetDetails(activityData.details.c_str());
		activity.GetAssets().SetLargeImage(activityData.largeImageText.c_str());

		ClearDiscordActivity(m_sCachedActivityData);
		m_sCachedActivityData = activityData;

		m_sState.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
		return;
	}

	std::string levelName = g_pMissionMgr->GetMissionName();

	// Ok, we're in singleplayer. Check if the level names match.
	// If they do, early return.
	if (!m_pCurrentLobby && levelName.compare(m_sCachedActivityData.details)) {
		return;
	}

	auto options = g_pClientMultiplayerMgr->GetServerGameOptions();
	auto pClientInfoMgr = g_pGameClientShell->GetInterfaceMgr()->GetClientInfoMgr();
	auto gameTypeStringID = options.GetGameTypeStringID();

	activityData.state = "Singleplayer";
	activityData.details = levelName;
	activityData.largeImageText = levelName;
	activityData.largeImageName = levelName;
	//activityData.largeImageName = GetLevelArt(g_pMissionMgr->GetCurrentWorldName()).c_str();
	activityData.currentPlayers = 1;
	activityData.maxPlayers = 1;

	activity.SetDetails(levelName.c_str());
	activity.SetState(activityData.state.c_str());

	if (gameTypeStringID > 0) {
		activityData.state = LoadTempString(options.GetGameTypeStringID());
		activity.SetState(activityData.state.c_str());
	}

	// Map
	activity.GetAssets().SetLargeImage(activityData.largeImageName.c_str());
	activity.GetAssets().SetLargeText(activityData.largeImageText.c_str());
	activity.SetInstance(true);

	// Set the party if we have a lobby
	if (m_pCurrentLobby) {
		activityData.maxPlayers = options.GetMaxPlayers();

		if (pClientInfoMgr) {
			activityData.currentPlayers = pClientInfoMgr->GetNumClients();
		}

		activityData.lobbyId = std::to_string(m_pCurrentLobby->GetId());
		activity.GetParty().GetSize().SetCurrentSize(activityData.currentPlayers);
		activity.GetParty().GetSize().SetMaxSize(activityData.maxPlayers);

		// Multiplayer early return point -- Maybe compare game mode?
		if (m_sCachedActivityData.currentPlayers == activityData.currentPlayers
			&& m_sCachedActivityData.maxPlayers == activityData.maxPlayers
			&& m_sCachedActivityData.details.compare(activityData.details) == 0
			&& m_sCachedActivityData.lobbyId.compare(activityData.lobbyId) == 0) {
			return;
		}

		// Handle lobby id and secret
		char secret[128];
		memset(secret, '\0', sizeof(secret));

		auto activitySecret = m_sState.core->LobbyManager().GetLobbyActivitySecret(m_pCurrentLobby->GetId(), secret);
		activity.GetParty().SetId(activityData.lobbyId.c_str());
		activity.GetSecrets().SetJoin(secret); // needed for ask to join to show up
	}


	ClearDiscordActivity(m_sCachedActivityData);
	m_sCachedActivityData = activityData;

	m_sState.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
		SDL_Log("Updated activity with result : %d", result);

		if (result != discord::Result::Ok) {
			SDL_Log("Error on updating activity! %d", result);
		}
	});
}

std::string DiscordMgr::GetLevelArt(std::string levelName)
{
#if 1
	if (levelName.compare("Unity HQ (8-16 Players)") == 0) {
		return "dm_05";
	}
	

	return "default";
#else // Too slow!
	std::vector<std::string> levelArtList = {
		"dm_05"
	};
	
	char pathName[128];
	char name[128];

	pathName[0] = '\0';
	name[0] = '\0';

	CHelpers::ExtractPathAndFileName(levelName.c_str(), pathName, name);


	for (std::vector<std::string>::iterator it = levelArtList.begin(); it != levelArtList.end(); ++it)
	{
		if (stricmp(name, it._Ptr->c_str()) == 0) {
			return it._Ptr->c_str();
		}
	}

	return "default";


#endif
}

