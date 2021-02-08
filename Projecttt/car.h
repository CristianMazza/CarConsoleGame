#pragma once

#include "console.h"
#include "map.h"
#include "game.h"
#include "obstacles.h"
#include <Windows.h>
#include <conio.h>
#include <winuser.h>


class car
{
private: 
	int xcar;
	int ycar;
	string name;
public:
	map mapz;
	console consolez;
	game *gamez;
	obstacles* obstaclez;

	car();
	void drawCar();
	void setMove();
	int getX();
	int getY();
	void setName();

	void setObstacle(obstacles* a);
	void setMap(map a);
	void setConsole(console a);
	void setGame(game *a);
};

