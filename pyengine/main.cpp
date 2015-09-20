
#include <stdio.h>
#include <tchar.h>
#include "pyengine.h"
#include "sys.h"

int main()
{
	PyEngine *pPyEngine = new PyEngine();
	delete pPyEngine;
    return 0;
}

