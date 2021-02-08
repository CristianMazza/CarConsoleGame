#pragma once

#include "console.h"
#include "map.h"
#include "ctime"

class game
{
private:
	int score;
	int level;
	int turbo;
	bool firstTurbo;
	int xGame;
	int yGame;
	int max_pt;
public: 
	game();

	map mapz;
	console consolez;

	void setLevel();
	int getScore();
	int getLevel();
	void printScore();
	void printLevel();
	void printLevelTitle();
	void printScoreTitle();
	void incScore();
	void decScore();
	void decTurbo();
	void getMax_pt();
	void printMax_ptTitle();
	void printTurboTitle();
	void printTurbo();
	void startTurbo();
	bool getFirstTurbo();
	void getConsole(console a);
	void getMap(map a);
	int getTurbo();
	void setFirstTurbo(bool flag);
	bool endGame();
};

