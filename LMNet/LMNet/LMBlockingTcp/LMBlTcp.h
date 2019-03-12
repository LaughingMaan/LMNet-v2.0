#pragma once

//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

//#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")
#define SHUT_RDWR 2  //shutdown both recieve and connect parameter

#include <winsock2.h>
class LMNET_API LMBlTcp
{
public:
	struct sockaddr_in stSockAddr;
	int i32SocketFD;
	int i32ConnectFD;
	int i32Res;
	int port;
	char* ip;
	bool closeFlag;
	LMBlTcp(char* _ip, int _port);
	LMBlTcp::LMBlTcp();
	void closeSocket();
	void closeConnection();
	virtual ~LMBlTcp();
	LMBlTcp& operator << (const char* msg);
	LMBlTcp& operator << (char msg[]);
	LMBlTcp& operator << (int msg);
	LMBlTcp& operator >> (char msg[]);
	LMBlTcp& operator >> (int msg);
	protected:
	private:
};

