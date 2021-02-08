#include "console.h"
#include "map.h"
#include "car.h"
#include "obstacles.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

bool play(console consolex) {
	map mapx = map();
	car carx = car();
	obstacles obsx = obstacles();
	game gamex = game();


	consolex.countdown();

	mapx.setConsole(consolex);

	carx.setMap(mapx);
	carx.setConsole(consolex);
	carx.setGame(&gamex);
	carx.setObstacle(&obsx);
	carx.setName();

	gamex.getConsole(consolex);

	obsx.setGame(&gamex);

	mapx.draw();

	carx.drawCar();

	gamex.printLevelTitle();
	gamex.printScoreTitle();
	gamex.printMax_ptTitle();
	gamex.printLevel();
	gamex.printScore();
	gamex.getMax_pt();
	gamex.printTurboTitle();
	gamex.printTurbo();

	obsx.listObstacles();

	obsx.TimeInit();

	while (gamex.getScore() > 0) {
		carx.setMove();
		obsx.ObsController();
		obsx.checkCollisionFirstObstacle(carx.getX(), carx.getY());
		obsx.checkCollisionSecondObstacle(carx.getX(), carx.getY());
		carx.setMove();
		obsx.checkCollisionFirstObstacle(carx.getX(), carx.getY());
		obsx.checkCollisionSecondObstacle(carx.getX(), carx.getY());
	}
	Sleep(100);
	return gamex.endGame();
}

int main() {
	console consolex;
	consolex.ShowConsoleCursor(false);
	consolex.message1();
	consolex.message2();
	bool check = true;
	while(check == true) {
		check = play(consolex);
	}
	return 0;
}
