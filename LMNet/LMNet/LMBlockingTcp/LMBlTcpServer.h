#pragma once
#include "LMBlTcp.h"
class LMBlTcpServer
{
public:
	LMNET_API LMBlTcpServer(int port);
	LMNET_API virtual ~LMBlTcpServer();
	LMBlTcp* socket;
	LMNET_API LMBlTcp* GetSocket();
	LMNET_API void AcceptClient();
protected:
private:
};
