#include "..\stdafx.h"
#include "LMBlTcpServer.h"


LMBlTcpServer::LMBlTcpServer(int port)
{
	//ctor
	socket = new LMBlTcp((char*)"", port);
	if (bind(socket->i32SocketFD, (struct sockaddr*) &(socket->stSockAddr), sizeof(socket->stSockAddr)) == -1) {
		perror("Bind error");
		socket->closeSocket();
	}

	if (listen(socket->i32SocketFD, 10) == -1) {
		perror("Listen error");
		socket->closeSocket();
	}



}

void LMBlTcpServer::AcceptClient() {
	socket->i32ConnectFD = accept(socket->i32SocketFD, 0, 0);
	if (socket->i32ConnectFD < 0) {
		perror("Accept error");
		std::cout << socket->i32ConnectFD << std::endl;
		socket->closeSocket();
		delete socket;
		exit(EXIT_FAILURE);
	}
}

LMBlTcpServer::~LMBlTcpServer()
{
	//dtor
}

LMBlTcp* LMBlTcpServer::GetSocket() {
	return socket;
}

