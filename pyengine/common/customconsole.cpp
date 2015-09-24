#include"customconsole.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;


#if PE_PLATFORM == PLATFORM_WIN32
#include <windows.h>

bool operator<(const std::pair<const char*, bool> & a, const std::pair<const char*, bool> & b)
{
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}
static map<pair <const char*, bool>, int> dConsoleColors;

void InitColorDict()
{
	dConsoleColors[make_pair((const char*)"red",       false)] = FOREGROUND_RED;
	dConsoleColors[make_pair((const char*)"red_h",     false)] = FOREGROUND_RED | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"green",     false)] = FOREGROUND_GREEN;
	dConsoleColors[make_pair((const char*)"green_h",   false)] = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"blue",      false)] = FOREGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"blue_h",    false)] = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"yellow",    false)] = FOREGROUND_RED | FOREGROUND_GREEN;
	dConsoleColors[make_pair((const char*)"yellow_h",  false)] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"cyan",      false)] = FOREGROUND_GREEN | FOREGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"cyan_h",    false)] = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"magenta",   false)] = FOREGROUND_BLUE | FOREGROUND_RED;
	dConsoleColors[make_pair((const char*)"magenta_h", false)] = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"white",     false)] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"white_h",   false)] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"red",       true)] = BACKGROUND_RED;
	dConsoleColors[make_pair((const char*)"red_h",     true)] = BACKGROUND_RED | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"green",     true)] = BACKGROUND_GREEN;
	dConsoleColors[make_pair((const char*)"green_h",   true)] = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"blue",      true)] = BACKGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"blue_h",    true)] = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"yellow",    true)] = BACKGROUND_RED | BACKGROUND_GREEN;
	dConsoleColors[make_pair((const char*)"yellow_h",  true)] = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"cyan",      true)] = BACKGROUND_GREEN | BACKGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"cyan_h",    true)] = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"magenta",   true)] = BACKGROUND_BLUE | BACKGROUND_RED;
	dConsoleColors[make_pair((const char*)"magenta_h", true)] = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
	dConsoleColors[make_pair((const char*)"white",     true)] = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	dConsoleColors[make_pair((const char*)"white_h",   true)] = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
}

WORD GetForeColor(const char* sTextColor)
{
	if (dConsoleColors.size() <= 0)
		InitColorDict();
	return dConsoleColors[make_pair(sTextColor, false)];
}

WORD GetBackColor(const char* sBackColor)
{
	if (dConsoleColors.size() <= 0)
		InitColorDict();
	return dConsoleColors[make_pair(sBackColor, true)];
}

template<typename AnyType>
void _printc(AnyType text, char *textColor, char *backColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle == 0)
		return;
	WORD fore = GetForeColor(textColor);
	WORD back = GetBackColor(backColor);

	//CONSOLE_SCREEN_BUFFER_INFO console_info;
	//GetConsoleScreenBufferInfo(handle, &console_info);
	SetConsoleTextAttribute(handle, fore | back | 128);
	std::cout << text;
	SetConsoleTextAttribute(handle, 128);
	//CloseHandle(handle);
}
#endif


void printc(char *sMsg, char *sTextColor, char *sBackColor)
{
#if PE_PLATFORM == PLATFORM_WIN32
	_printc(sMsg, sTextColor, sBackColor);
#else
	cout << sMsg;
#endif
}



