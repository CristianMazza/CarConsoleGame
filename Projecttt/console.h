#pragma once
#include <iostream>
#include <cstring>
#include "Windows.h"
#include <conio.h>

using namespace std;

class console
{
private:
	HANDLE consolehand;
public:
	console();

	void setWindow();
	void ShowConsoleCursor(bool flag);
	void gotoconsole(short x, short y);
	void message1();
	void message2();
	void countdown();
	void setGreenColor(bool flag);

};

