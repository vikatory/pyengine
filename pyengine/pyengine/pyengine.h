#pragma once
#include <iostream>

class PyEngine
{
public:
	PyEngine();
	~PyEngine();

	void init();
	void test();
	std::string eval(const char *expression);
	void exec(const char *code);
	void execFile(const char *filename);
	std::string scriptPath();
private:
};

