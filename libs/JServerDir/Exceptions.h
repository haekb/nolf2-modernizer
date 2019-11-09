#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <WinSock2.h>


class OperationNotSupported : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Operation not supported.";
	}
};

class UnknownSocketError : public std::exception
{
	virtual const char* message() const throw()
	{
		int error = WSAGetLastError();
		std::string errorMsg = "Unknown socket error " + std::to_string(error);

		return errorMsg.c_str();
	}
};