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

class DiscordMgr
{
public:
	DiscordMgr();
	~DiscordMgr();

	void Init();
	void Update();

	bool CreateLobby(StartGameRequest* pGameRequest);
	bool JoinLobby();


	// discord
	discord::Core* m_pCore;
	DiscordState m_sState;

protected:

private:

};