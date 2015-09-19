
#include <stdio.h>
#include <tchar.h>
#include "pyengine.h"

int main()
{
	PyEngine *pPyEngine = new PyEngine();
	pPyEngine->init();
	delete pPyEngine;
    return 0;
}

