// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // »сключите редко используемые компоненты из заголовков Windows
// ‘айлы заголовков Windows:
#include <windows.h>

#ifdef LMNET_EXPORTS
#define LMNET_API __declspec(dllexport)
#else
#define LMNET_API __declspec(dllimport)
#endif

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")