#pragma once
#include "console.h"

class map
{
private:
	int width;
	int height;
public:
	console consolez;

	map();
	void draw();
	void setConsole(console a);
	int getwidth();
	int getheight();

};

