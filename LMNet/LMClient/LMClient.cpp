// LMClient.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <LMNet.h>
#include <iostream>
#include <cstdlib>
//#pragma comment( lib, "..\Debug\LMNet.lib" )
using namespace std;
int main()
{
	char msg[64] = { 0 };
	LMBlTcpClient desc("127.0.0.1", 1100);
	LMBlTcp* socket = desc.GetSocket();
	while (1) {
		try {
			cout << "Define a message: " << endl;
			//scanf("%s", (char*)&msg);
			cin.getline((char*)&msg, 64, '\n');
			cin.ignore();
			if (strcmp(msg, "kill") == 0)
				break;
			// cout<<"("<<msg<<")"<<endl;
			*socket << msg;
		}
		catch (exception ex) {
			cout << "EXCEPTION: " << ex.what() << endl;
		}
	}
	system("pause");
    return 0;
}

