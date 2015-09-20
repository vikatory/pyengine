#include "pyengine.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "sys.h"
#include <boost/python.hpp>

using namespace std;

namespace bf = boost::filesystem;				// �򵥱���
namespace python = boost::python;

PyEngine::PyEngine()
{
	init();
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
	bf::path oCurPath = bf::current_path();		// ȡ�õ�ǰĿ¼, һ����cpp�ļ��У�����exe�ó������У�����exe���ڵ��ļ���
	string sCurPath = oCurPath.string();
	cout << sCurPath << endl;
	// ͨ�����û�����������dll·��
	SetEnviromentValue("PYTHONPATH", "E:\\CODE\\project_1\\python-3.5.0-embed-amd64;E:\\CODE\\project_1\\python-3.5.0-embed-amd64\\Lib");
	Py_SetProgramName(L"python35");
	Py_Initialize();
	//using namespace boost::python;				// ����������Ч
	test();

}

std::string PyEngine::eval(std::string expression)  // eval�������Լ���Python���ʽ�������ؽ��
{
	python::object oPyMainModule = python::import("__main__");
	python::object oPyMainNamespace = oPyMainModule.attr("__dict__");
	python::object oResult = python::eval(expression.c_str(), oPyMainNamespace);
	std::string sValue = python::extract<std::string>(oResult) BOOST_EXTRACT_WORKAROUND;
	return sValue;
}

void PyEngine::exec(std::string code)  // ͨ��exec����ִ�ж�̬Python���룬exec�����ؽ��
{
	python::object oPyMainModule = python::import("__main__");
	python::object oPyMainNamespace = oPyMainModule.attr("__dict__");
	python::object oResult = python::exec(code.c_str(), oPyMainNamespace);
}

void PyEngine::test()
{
	exec("a='11ass77'");
	string value = eval("a.upper()");
	cout << value << endl;

	//object main_module = import("__main__");
	//if (python::handle_exception(eval_test)) {
	//	check_pyerr();
	//}
}



