#include "pyengine.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "sys.h"
#include <boost/python.hpp>

using namespace std;

namespace bf = boost::filesystem;				// �򵥱���


PyEngine::PyEngine()
{
}

PyEngine::~PyEngine()
{
	// Boost.Python doesn't support Py_Finalize yet.
	// Py_Finalize();
}

void PyEngine::init()
{
	bf::path oCurPath = bf::current_path();		// ȡ�õ�ǰĿ¼, һ����cpp�ļ��У�����exe�ó������У�����exe���ڵ��ļ���
	string sCurPath = oCurPath.string();
	cout << sCurPath << endl;
	SetEnviromentValue("PYTHONPATH", "E:\\CODE\\project_1\\Python-3.5.0\\Lib");
	Py_Initialize();

	
}







