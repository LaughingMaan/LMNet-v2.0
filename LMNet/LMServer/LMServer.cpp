// LMServer.cpp: определяет точку входа для консольного приложения.
//
 #pragma comment(lib, "..\Debug\LMNet.lib")
#include "stdafx.h"
#include <LMNet.h>
#include <iostream>
#include <cstdlib>
#define port	1100

using namespace std;
int main()
{
	LMBlTcpServer server(1100);
	LMBlTcp* socket = server.GetSocket();
	char recvbuf[64] = { 0 };
	for (;;) {
		server.AcceptClient();
		cout << sizeof(recvbuf) << endl;
		while (true) {

			*socket >> recvbuf;
			cout << recvbuf << endl;
			if (socket->closeFlag)
				break;
		}
		cout << "Client disconnected" << endl;
		socket->closeConnection();
	}
	delete socket;
	system("pause");
    return 0;
}

