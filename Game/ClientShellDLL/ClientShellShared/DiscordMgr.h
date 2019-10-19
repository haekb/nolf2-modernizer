#pragma once
#include <array>
#include <vector>

#include "discord.h"
#include <discord-secret.h>

#include "ClientMultiplayerMgr.h"

struct DiscordState {
	discord::User currentUser;


	std::unique_ptr<discord::Core> core;
};

// Mainly for hashing
struct DiscordActivityData {
	std::string state;
	std::string details;
	std::string largeImageName;
	std::string largeImageText;
	int currentPlayers;
	int maxPlayers;
	std::string lobbyId;
	bool inMenu;
};

class DiscordMgr
{
public:
	DiscordMgr();
	~DiscordMgr();

	void Init();
	void Update();

	bool CreateLobby(StartGameRequest* pGameRequest);
	bool JoinLobby(discord::Lobby const& lobby);
	bool LeaveLobby();

	void UpdateActivity();

	std::string GetLevelArt(std::string levelName);


	// discord
	discord::Core* m_pCore;
	DiscordState m_sState;
	discord::Lobby* m_pCurrentLobby;
	// FIXME: maybe find a better way to handle lobbies.
	discord::Lobby m_InternalCurrentLobby;

	DiscordActivityData m_sCachedActivityData;

	inline void ClearDiscordActivity(DiscordActivityData &activityData) {
		activityData = {
			"",
			"",
			"",
			"",
			0,
			1,
			"",
			false
		};
	}

protected:

private:



};