#pragma once
#include <iostream>

class PyEngine
{
public:
	PyEngine();
	~PyEngine();

	void init();
	void test();
	std::string eval(std::string const &expression);
	void exec(std::string const &code);
	void exec_file(std::string const &filename);
private:
	//void execPyFile(std::string const &filename);
};

