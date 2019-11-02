#include "pch.h"
#include "UDPSocket.h"

UDPSocket::UDPSocket()
{
	m_Socket = NULL;
	SetupSocket();
}

UDPSocket::~UDPSocket()
{
	if (m_Socket == NULL) {
		return;
	}

	closesocket(m_Socket);
	m_Socket = NULL;
}

void UDPSocket::SetupSocket()
{
	int type = SOCK_DGRAM;
	IPPROTO protocol = IPPROTO_UDP;

	m_Socket = socket(AF_INET, type, protocol);

	if (m_Socket == INVALID_SOCKET) {
		throw UnknownSocketError();
	}

	timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;

	setsockopt(m_Socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
	setsockopt(m_Socket, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));

	int enable = 1;
	setsockopt(m_Socket, SOL_SOCKET, SO_REUSEADDR, (char*)&enable, sizeof(int));

	return;
}

void UDPSocket::Bind(ConnectionData connectionData)
{
	ULONG iBuffer = 0;

	// Setup our address - INADDR_ANY
	inet_pton(AF_INET, connectionData.sIp.c_str(), (ULONG*)&iBuffer);

	sockaddr_in  saAddress;
	saAddress.sin_family = AF_INET;
	saAddress.sin_addr.s_addr = iBuffer;
	saAddress.sin_port = htons(connectionData.nPort);

	int iResult = bind(m_Socket, (SOCKADDR*)&saAddress, sizeof(saAddress));

	if (iResult == INVALID_SOCKET)
	{
		throw UnknownSocketError();
	}

	return;
}

void UDPSocket::Connect(ConnectionData connectionData)
{
	// Can't connect on udp
	throw OperationNotSupported();
}

void UDPSocket::Query(std::string sQuery, ConnectionData connectionData)
{
	ULONG iBuffer = 0;

	// Setup our address
	inet_pton(AF_INET, connectionData.sIp.c_str(), (ULONG*)&iBuffer);

	sockaddr_in  saAddress;
	saAddress.sin_family = AF_INET;
	saAddress.sin_addr.s_addr = iBuffer;
	saAddress.sin_port = htons(connectionData.nPort);

	// Send our query!
	int iResult = 0;
	int iIndex = 0;
	int iLeft = sQuery.size();
	char* szQueryBuffer = (char*)sQuery.c_str();

	while (iLeft > 0) {
		iResult = sendto(m_Socket, &szQueryBuffer[iIndex], iLeft, 0, (SOCKADDR*)&saAddress, sizeof(saAddress));

		if (iResult == SOCKET_ERROR) {
			int error = WSAGetLastError();

			// That's okay!
			if (error == WSAETIMEDOUT) {
				continue;
			}

			throw UnknownSocketError();
		}

		// Servers trying to catch up...give it a breather
		if (iResult == 0) {
			Sleep(500);
		}

		iIndex += iResult;
		iLeft -= iResult;
	}

	return;
}

std::string UDPSocket::Recieve(ConnectionData& connectionData)
{
	ULONG iBuffer = 0;
	char szBuffer[2048];
	memset(szBuffer, 0, sizeof(szBuffer));

	// Setup our address
	inet_pton(AF_INET, connectionData.sIp.c_str(), (ULONG*)&iBuffer);

	sockaddr_in  saAddress;
	saAddress.sin_family = AF_INET;
	saAddress.sin_addr.s_addr = iBuffer;
	saAddress.sin_port = htons(connectionData.nPort);

	int fromSize = sizeof(saAddress);
	int iResult = -1;

	std::string sBuffer = "";

	int loopIterations = 0;

	while (iResult != 0) {
		loopIterations++;

		iResult = recvfrom(m_Socket, szBuffer, sizeof(szBuffer), 0, (SOCKADDR*)&saAddress, &fromSize);

		if (iResult == SOCKET_ERROR) {
			int error = WSAGetLastError();

			// Prevent infinite loop
			if (loopIterations > 10) {
				break;
			}

			// That's okay!
			if (error == WSAETIMEDOUT) {
				Sleep(1000);
				continue;
			}

			throw UnknownSocketError();
		}

		if (iResult == 0) {
			break;
		}

		sBuffer += szBuffer;

		size_t found = sBuffer.find("\\final\\");

		// Also okay, if final is in, we done!
		if (found != std::string::npos) {
			break;
		}
	}

	char addressBuffer[32];
	memset(addressBuffer, 0, sizeof(addressBuffer));

	sprintf(addressBuffer, "%d.%d.%d.%d", saAddress.sin_addr.S_un.S_un_b.s_b1, saAddress.sin_addr.S_un.S_un_b.s_b2, saAddress.sin_addr.S_un.S_un_b.s_b3, saAddress.sin_addr.S_un.S_un_b.s_b4);

	connectionData.sIp = addressBuffer;
	connectionData.nPort = htons(saAddress.sin_port);

	return sBuffer;
}