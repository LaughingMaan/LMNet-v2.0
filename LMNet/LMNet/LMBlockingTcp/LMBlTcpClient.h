#pragma once
#include "LMBlTcp.h"
class LMBlTcpClient
{
public:
	LMNET_API LMBlTcpClient(const char* ip, int port);
	LMNET_API virtual ~LMBlTcpClient();
	LMBlTcp* socket;
	LMNET_API LMBlTcp* GetSocket();
protected:
private:
};

