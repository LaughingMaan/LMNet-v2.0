#include "..\stdafx.h"
#include "LMBlTcp.h"


LMBlTcp::LMBlTcp()
{
}

LMBlTcp::LMBlTcp(char* _ip, int _port)
{
	//ctor
	port = _port;
	memset(&stSockAddr, 0, sizeof(stSockAddr));
	stSockAddr.sin_family = PF_INET;
	stSockAddr.sin_port = htons(port);
	ip = _ip;
	i32Res = 0;
	i32ConnectFD = 0;
	closeFlag = false;
	if (strcmp(ip, "") == 0)
		stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		i32Res = inet_pton(PF_INET, ip, &stSockAddr.sin_addr);

	i32SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

}
LMBlTcp& LMBlTcp::operator << (const char* msg) {
	if (send(i32SocketFD, msg, strlen(msg) + 1, 0) < 0)
		std::cout << "Send Error!" << std::endl;
	return *this;
}

LMBlTcp& LMBlTcp::operator << (char msg[]) {
	// std::cout<<"msg sent: "<<msg<<std::endl;
	if (send(i32SocketFD, msg, strlen(msg) + 1, 0) < 0)
		std::cout << "Send Error!" << std::endl;
	return *this;
}

LMBlTcp& LMBlTcp::operator << (int msg) {

	return *this;
}

LMBlTcp& LMBlTcp::operator >> (char msg[]) {
	std::cout << sizeof(msg) << std::endl;
	int i = recv(i32ConnectFD, msg, sizeof(msg), 0);
	if (i == 0)
		std::cout << "Empty msg \n";//closeFlag = true;
	else {
		msg[i] = '\0';
		//printf("Recieved: %s\n", msg);
	}
	return *this;
}

LMBlTcp& LMBlTcp::operator >> (int msg) {

	return *this;
}
LMBlTcp::~LMBlTcp()
{
	//dtor
	shutdown(i32SocketFD, SHUT_RDWR);
	closesocket(i32SocketFD);
}
void LMBlTcp::closeSocket() {
	closesocket(i32SocketFD);
}

void LMBlTcp::closeConnection() {
	shutdown(i32ConnectFD, SHUT_RDWR);
	closesocket(i32ConnectFD);
}
