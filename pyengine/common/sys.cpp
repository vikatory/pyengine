#include "sys.h"
#include "platform.h"
#include <iostream>

#if PE_PLATFORM == PLATFORM_WIN32
#include <windows.h>
#include<tchar.h>
#endif

using namespace std;

void SetEnviromentValue(string sKey, string sValue)
{
#if PE_PLATFORM == PLATFORM_WIN32
	WCHAR wsKey[1024];
	memset(wsKey, 0, sizeof(wsKey));
	MultiByteToWideChar(CP_ACP, 0, sKey.c_str(), (int)strlen(sKey.c_str()) + 1, wsKey, int(sizeof(wsKey) / sizeof(wsKey[0])));
	WCHAR wsValue[1024];
	memset(wsValue, 0, sizeof(wsValue));
	MultiByteToWideChar(CP_ACP, 0, sValue.c_str(), (int)strlen(sValue.c_str()) + 1, wsValue, int(sizeof(wsValue) / sizeof(wsValue[0])));
	SetEnvironmentVariable(wsKey, wsValue);

	return;

	LPTSTR lpszVariable;
	LPTCH lpvEnv;

	//获得环境变量内存块的指针
	lpvEnv = GetEnvironmentStrings();
	if (lpvEnv == NULL)
	{
		printf("GetEnvironmentStrins failed(%d)/n", GetLastError());
		return ;
	}

	//环境变量字符串是以NULL分隔的，内存块以NULL结尾
	lpszVariable = (LPTSTR)lpvEnv;

	while (*lpszVariable)
	{
		_tprintf(TEXT("%s/n"), lpszVariable);
		wcout << lpszVariable << "------------------"<<endl;
		lpszVariable += lstrlen(lpszVariable) + 1;   //移动指针
	}

	FreeEnvironmentStrings(lpvEnv);


#endif
}


