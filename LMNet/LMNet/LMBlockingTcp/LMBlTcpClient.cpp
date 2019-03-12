#include "..\stdafx.h"
#include "LMBlTcpClient.h"



LMBlTcpClient::LMBlTcpClient(const char* ip, int port)
{
	socket = new LMBlTcp((char*)ip, port);
	if (socket->i32Res < 0) {
		perror("Error: bad firs arg");
		delete socket;
		//	return EXIT_FAILURE;
	}
	else if (!socket->i32Res) {
		perror("Error: incorrect IP");
		delete socket;
		//	return EXIT_FAILURE;
	}
	if (connect(socket->i32SocketFD, (const struct sockaddr*) &socket->stSockAddr, sizeof(socket->stSockAddr)) == -1) {
		perror("Connection error");
		delete socket;
		//	return EXIT_FAILURE;
	}
}

LMBlTcp* LMBlTcpClient::GetSocket() {
	return socket;
}
LMBlTcpClient::~LMBlTcpClient()
{
	delete socket;
}
