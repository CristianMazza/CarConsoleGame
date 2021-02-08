#include "car.h"

car::car() {
	xcar = (mapz.getwidth() / 2) - 1;
	ycar = mapz.getheight() - 2;
	name = "";
	gamez = NULL;
}

void car::setMove() {
	if (gamez->getTurbo() > 0) {
		consolez.setGreenColor(true);
		if (gamez->getFirstTurbo() == true) {
			drawCar();
			gamez->setFirstTurbo(false);
		}
	}
	if (GetKeyState(VK_LEFT) & 0x800) {
		if (xcar != 2) {
			consolez.gotoconsole(xcar + 1, ycar - 2);
			cout << " ";
			consolez.gotoconsole(xcar + 2, ycar - 1);
			cout << " ";
			consolez.gotoconsole(xcar + 1, ycar);
			cout << " ";
			xcar = xcar - 1;
			drawCar();
		}
		else {
			consolez.gotoconsole(xcar, ycar -1);
			cout << "X";
			gamez->decScore();
			gamez->printScore();
		}
		Sleep(150);
	}
	else if (GetKeyState(VK_RIGHT) & 0x800) {
		if (xcar != mapz.getwidth() - 4) {
			consolez.gotoconsole(xcar+1, ycar - 2);
			cout << " ";
			consolez.gotoconsole(xcar, ycar - 1);
			cout << " ";
			consolez.gotoconsole(xcar+1, ycar);
			cout << " ";
			xcar = xcar + 1;
			drawCar();
		}
		else {
			consolez.gotoconsole(xcar+2, ycar-1);
			cout << "X";
			gamez->decScore();
			gamez->printScore();
		}
		Sleep(150);
	}
	if (gamez->getTurbo() > 0) consolez.setGreenColor(false);
}



void car::drawCar() {
	bool coll = obstaclez->getCollision();
	if (coll == false) {
		consolez.gotoconsole(xcar+1, ycar - 2);
		cout << "*";
		consolez.gotoconsole(xcar, ycar - 1);
		cout << "*" << name[0] <<"*";
		consolez.gotoconsole(xcar+1, ycar);
		cout << "*";
	}
	else {
		consolez.gotoconsole(xcar+1, ycar - 2);
		cout << "*";
		consolez.gotoconsole(xcar, ycar - 1);
		cout << "XXX";
		consolez.gotoconsole(xcar+1, ycar);
		cout << "*";
	}
}

int car::getX() {
	return xcar;
}

int car::getY() {
	return ycar;
}

void car::setName() {
	srand(time(NULL));
	name = 'A' + rand() % 26;
}

void car::setObstacle(obstacles* a) {
	obstaclez = a;
}

void car::setMap(map a) {
	mapz = a;
}

void car::setConsole(console a) {
	consolez = a;
}

void car::setGame(game *a) {
	gamez = a;
}