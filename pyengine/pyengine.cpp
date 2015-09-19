#include "pyengine.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "sys.h"
#include <boost/python.hpp>

using namespace std;

namespace bf = boost::filesystem;				// 简单别名


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
	bf::path oCurPath = bf::current_path();		// 取得当前目录, 一般是cpp文件夹，若把exe拿出来运行，就是exe所在的文件夹
	string sCurPath = oCurPath.string();
	cout << sCurPath << endl;
	SetEnviromentValue("PYTHONPATH", "E:\\CODE\\project_1\\Python-3.5.0\\Lib");
	Py_Initialize();

	
}







