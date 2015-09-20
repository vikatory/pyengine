#include "pyengine.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "sys.h"
#include <boost/python.hpp>

using namespace std;

namespace bf = boost::filesystem;				// 简单别名
namespace python = boost::python;

PyEngine::PyEngine()
{
}

PyEngine::~PyEngine()
{
	// Boost.Python doesn't support Py_Finalize yet.
	// Py_Finalize();
}







#include <boost/detail/lightweight_test.hpp>


void eval_test()
{
	python::object result = python::eval("'abcdefg'.upper()");
	std::string value = python::extract<std::string>(result) BOOST_EXTRACT_WORKAROUND;
	BOOST_TEST(value == "ABCDEFG");
}

void check_pyerr(bool pyerr_expected = false)
{
	if (PyErr_Occurred())
	{
		if (!pyerr_expected) {
			BOOST_ERROR("Python Error detected");
			PyErr_Print();
		}
		else {
			PyErr_Clear();
		}
	}
	else
	{
		BOOST_ERROR("A C++ exception was thrown  for which "
			"there was no exception handler registered.");
	}
}



void PyEngine::init()
{
	bf::path oCurPath = bf::current_path();		// 取得当前目录, 一般是cpp文件夹，若把exe拿出来运行，就是exe所在的文件夹
	string sCurPath = oCurPath.string();
	cout << sCurPath << endl;
	// 通过设置环境变量包含dll路径
	SetEnviromentValue("PYTHONPATH", "E:\\CODE\\project_1\\python-3.5.0-embed-amd64;E:\\CODE\\project_1\\python-3.5.0-embed-amd64\\Lib");
	Py_SetProgramName(L"python35");
	Py_Initialize();

	using namespace boost::python;				// 作用域类有效
	//object main_module = import("__main__");

//#include <boost/detail/lightweight_test.hpp>
	python::object result = python::eval("'abcdefg'.upper()");
	std::string value = python::extract<std::string>(result) BOOST_EXTRACT_WORKAROUND;
	cout << value << endl;
	BOOST_TEST(value == "ABCDEFG");

	//object main_module = import("__main__");
	//if (python::handle_exception(eval_test)) {
	//	check_pyerr();
	//}
	
}




