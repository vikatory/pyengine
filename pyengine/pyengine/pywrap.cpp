#include "pywrap.h"
#include <boost/python.hpp>
#include <boost/detail/lightweight_test.hpp>

#include "commonpyfunc.h"

using namespace boost::python;

BOOST_PYTHON_FUNCTION_OVERLOADS(cwrite_overloads, cwrite, 1, 3)

BOOST_PYTHON_MODULE(cm)
{
	def("cwrite", cwrite, cwrite_overloads());
}


void registerPyFuncs()
{
#include<iostream>
	// ע��ģ�鵽��������
	if (PyImport_AppendInittab(const_cast<char*>("cm"),
#if PY_VERSION_HEX >= 0x03000000 
		PyInit_cm
#else 
		initcm
#endif 
		) == -1)
		throw std::runtime_error("��cm��Ϊ�ڽ�ģ����ص�������ʧ��");
}


