// Приведенный ниже блок ifdef - это стандартный метод создания макросов, упрощающий процедуру 
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа LMNET_EXPORTS,
// в командной строке. Этот символ не должен быть определен в каком-либо проекте
// использующем данную DLL. Благодаря этому любой другой проект, чьи исходные файлы включают данный файл, видит 
// функции LMNET_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
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

// Этот класс экспортирован из LMNet.dll
class LMNET_API CLMNet {
public:
	CLMNet(void);
	// TODO: Добавьте здесь свои методы.
};

extern LMNET_API int nLMNet;

LMNET_API int fnLMNet(void);
