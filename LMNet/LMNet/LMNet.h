// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ��������� 
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� LMNET_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, ����� 
// ������� LMNET_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
#ifdef LMNET_EXPORTS
#define LMNET_API __declspec(dllexport)
#else
#define LMNET_API __declspec(dllimport)
#endif

#include "LMBlockingTcp\LMBlTcpClient.h"
#include "LMBlockingTcp\LMBlTcpServer.h"



//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <unistd.h>

#define LMVersion           "0.1.1.1"
#define LMVersionRelease    0
#define LMVersionInterface  1
#define LMVersionKernel     1
#define LMVersionModify     1

// ���� ����� ������������� �� LMNet.dll
class LMNET_API CLMNet {
public:
	CLMNet(void);
	// TODO: �������� ����� ���� ������.
};

extern LMNET_API int nLMNet;

LMNET_API int fnLMNet(void);
