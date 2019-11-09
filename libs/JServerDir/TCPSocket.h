#pragma once
#include "ISocket.h"
class TCPSocket :
	public ISocket
{
public:

	TCPSocket();
	~TCPSocket();

	virtual void SetupSocket();
	virtual void Bind(ConnectionData connectionData);
	virtual void Connect(ConnectionData connectionData);
	virtual void Query(std::string sQuery, ConnectionData connectionData);
	virtual std::string Recieve(ConnectionData& connectionData);

protected:
	SOCKET m_Socket;

	bool m_bConnected;
};

