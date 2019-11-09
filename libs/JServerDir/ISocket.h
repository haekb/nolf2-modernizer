#pragma once

#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>

struct ConnectionData {
	std::string sIp;
	unsigned short nPort;
};

class ISocket
{
public:
	// Note: Socket is handled internally
	virtual void SetupSocket() = 0;
	virtual void Bind(ConnectionData connectionData) = 0;
	virtual void Connect(ConnectionData connectionData) = 0;
	virtual void Query(std::string sQuery, ConnectionData connectionData) = 0;
	virtual std::string Recieve(ConnectionData &connectionData) = 0;
};

