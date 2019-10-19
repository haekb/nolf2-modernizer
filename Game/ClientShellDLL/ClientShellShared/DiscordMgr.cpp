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

		UpdateActivity();
	}

	return bOk;
}

bool DiscordMgr::LeaveLobby()
{
	m_pCurrentLobby = NULL;
	return true;
}

void DiscordMgr::UpdateActivity()
{
	discord::Activity activity{};

	// TODO: Cache a token, so we don't have to actually update the activity if we don't need to!

	if (!g_pGameClientShell->GetPlayerMgr()->IsPlayerInWorld()) {
		activity.SetState("In Menu");
		activity.SetDetails("Doing non-essential stuff");
		activity.GetAssets().SetLargeImage("default");
		m_sState.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
		return;
	}

	std::string levelName = g_pMissionMgr->GetMissionName();

	auto options = g_pClientMultiplayerMgr->GetServerGameOptions();
	auto request = g_pClientMultiplayerMgr->GetStartGameRequest();

	auto netSession = request.m_pNetSession;

	auto pClientInfoMgr = g_pGameClientShell->GetInterfaceMgr()->GetClientInfoMgr();

	g_pClientMultiplayerMgr->GetNetClientData();
	
	activity.SetDetails(levelName.c_str());

	auto gameTypeStringID = options.GetGameTypeStringID();

	activity.SetState("Singleplayer");

	if (gameTypeStringID > 0) {
		activity.SetState(LoadTempString(options.GetGameTypeStringID()));
	}

	// Set the party if we have a lobby
	if (m_pCurrentLobby) {
		char secret[128];
		memset(secret, '\0', sizeof(secret));

		auto activitySecret = m_sState.core->LobbyManager().GetLobbyActivitySecret(m_pCurrentLobby->GetId(), secret);

		activity.GetParty().SetId(std::to_string(m_pCurrentLobby->GetId()).c_str());

		int currentPlayers = 1;
		int maxPlayers = options.GetMaxPlayers();

		if (pClientInfoMgr) {
			currentPlayers = pClientInfoMgr->GetNumClients();
		}

		activity.GetParty().GetSize().SetCurrentSize(currentPlayers);
		activity.GetParty().GetSize().SetMaxSize(maxPlayers);
		activity.GetSecrets().SetJoin(secret); // needed for ask to join to show up
	}

	// Map
	activity.GetAssets().SetLargeImage(GetLevelArt(g_pMissionMgr->GetCurrentWorldName()).c_str());
	activity.GetAssets().SetLargeText(levelName.c_str());
	activity.SetInstance(true);

	m_sState.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
		if (result != discord::Result::Ok) {
			SDL_Log("Error on updating activity! %d", result);
		}
	});
}

std::string DiscordMgr::GetLevelArt(std::string levelName)
{
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
}
