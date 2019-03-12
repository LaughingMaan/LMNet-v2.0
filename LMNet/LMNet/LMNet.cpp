// LMNet.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "LMNet.h"


// Пример экспортированной переменной
LMNET_API int nLMNet=0;

// Пример экспортированной функции.
LMNET_API int fnLMNet(void)
{
    return 42;
}

// Конструктор для экспортированного класса.
// см. определение класса в LMNet.h
CLMNet::CLMNet()
{
    return;
}
