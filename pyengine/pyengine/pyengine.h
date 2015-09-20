#pragma once
#include <iostream>

class PyEngine
{
public:
	PyEngine();
	~PyEngine();

	void init();
	void test();
	std::string eval(std::string expression);
	void exec(std::string code);
};

