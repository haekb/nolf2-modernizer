#include "stdafx.h"
#include "DiscordMgr.h"
#include <iostream>
#include <SDL.h>

DiscordMgr* g_pDiscordMgr;

void LogProblemsFunction(discord::LogLevel level, std::string message)
{
	SDL_Log("[Discord] %d - %s", level, message);
}

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

	SDL_Log("Discord Game SDK setup!");
}

void DiscordMgr::Update()
{
	m_sState.core->RunCallbacks();
}

bool DiscordMgr::CreateLobby(ServerGameOptions* pGameOptions)
{




	discord::LobbyTransaction lobby{};
	m_sState.core->LobbyManager().GetLobbyCreateTransaction(&lobby);
	lobby.SetCapacity(pGameOptions->GetMaxPlayers());
	lobby.SetType(discord::LobbyType::Public);

	m_sState.core->LobbyManager().CreateLobby(
		lobby,
		[](discord::Result result, discord::Lobby const& lobby) {
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
			activity.SetState("In Lobby");
			activity.GetParty().SetId("ahhhh");
			activity.GetSecrets().SetJoin("unique"); // needed for ask to join to show up
			activity.GetAssets().SetLargeImage("default");
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
