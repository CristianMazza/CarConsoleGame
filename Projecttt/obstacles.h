#pragma once

#include "console.h"
#include "map.h"
#include "game.h"

#include <ctime>

struct obstacle {
	string str = "";
	int xobs = 1;
	int yobs = -1;
	bool isVisible = false;
	obstacle* next = NULL;
};
typedef obstacle* ptr_lista;


class obstacles{

private:
	ptr_lista p, last;
	int n;
	clock_t timex;
	int mood;
	bool collision;
public:
	console consolez;
	map mapz;
	game *gamez;

	obstacles();
	void addElement();
	void TimeInit();
	void ObsController();
	void drawObstacle();
	void goDownObstacle();
	void checkCollisionFirstObstacle(int x, int y);
	void checkCollisionSecondObstacle(int x, int y);
	void deleteObstacle(ptr_lista p_delete);
	void setCollision(bool coll);
	bool getCollision();
	void listObstacles();

	int getNumber();
	void decNumber();

	void setConsole(console a);
	void setMap(map a);
	void setGame(game *a);
};

