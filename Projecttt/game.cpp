#include "game.h"


game::game() {
	score = 10;
	level = 1;
	turbo = 0;
	firstTurbo = false;
	xGame = mapz.getwidth() + 5;
	yGame = mapz.getheight() / 2 - 3;
	max_pt = 10;
}

void game::printLevel() {
	consolez.gotoconsole(xGame + 12, yGame);
	cout << "   ";
	consolez.gotoconsole(xGame + 12, yGame);
	cout << level;
}

void game::printScore() {
	consolez.gotoconsole(xGame + 12, yGame + 1);
	cout << "         ";
	consolez.gotoconsole(xGame + 12, yGame + 1);
	cout << score;
}

void game::printLevelTitle() {
	consolez.gotoconsole(xGame, yGame);
	cout << "LEVEL:";
}

void game::printScoreTitle() {
	consolez.gotoconsole(xGame, yGame + 1);
	cout << "SCORE:";
}

void game::printTurboTitle() {
	consolez.gotoconsole(xGame, yGame + 5);
	cout << "TURBO:";
}

void game::printTurbo(){
	consolez.gotoconsole(xGame + 12, yGame + 5);
	cout << turbo;
}

void game::setLevel() {
	if (score < 200) {
		level = 1;
	}
	else if (score >= 200 && score < 400) {
		level = 2;
	}
	else if (score >= 400 && score < 600) {
		level = 3;
	}
	else if (score >= 600 && score < 800) {
		level = 4;
	}
	else if (score >= 800 && score < 1000) {
		level = 5;
	}
	else if (score >= 1000 && score < 1200) {
		level = 6;
	}
	else if (score >= 1200 && score < 1400) {
		level = 7;
	}
	else if (score >= 1400 && score < 1600) {
		level = 8;
	}
	else if (score >= 1600 && score < 1800) {
		level = 9;
	}
	else if (score >= 1800) {
		level = 10;
	}
}

void game::printMax_ptTitle() {
	consolez.gotoconsole(xGame, yGame + 2);
	cout << "BEST SCORE: " << score;
}

void game::getMax_pt() {
	if (score > max_pt) {
		max_pt = score;
		consolez.gotoconsole(xGame + 12, yGame + 2);
		cout << max_pt;
	}
}

int game::getLevel() {
	setLevel();
	return level;
}

int game::getScore() {
	return score;
}

void game::incScore() {
	score = score + 10;
}

void game::decScore() {
	score = score - 30;
}

void game::getConsole(console a) {
	consolez = a;
}

void game::getMap(map a) {
	mapz = a;
}

int game::getTurbo() {
	return turbo;
}

void game::decTurbo() {
	turbo = turbo - 1;
}

void game::startTurbo() {
	srand(time(NULL));
	turbo = (rand() % 8) + 1;
}

bool game::getFirstTurbo() {
	return firstTurbo;
}

void game::setFirstTurbo(bool flag) {
	firstTurbo = flag;
}

bool game::endGame() {
	system("cls");
	consolez.setWindow();
	consolez.gotoconsole(10, 10);
	cout << "Oh no, hai perso la partita!";
	consolez.gotoconsole(10, 11);
	cout << "Il punteggio migliore e' stato: " << max_pt;
	consolez.gotoconsole(10, 12);
	cout << "Se vuoi rigiocare premi il tasto 'Enter', altrimenti 'ESC'.";

	int mood = 0;
	while (mood == 0) {
		if (GetKeyState(VK_ESCAPE) & 0x800) {
			mood = 1;
		}
		else if (GetKeyState(VK_RETURN) & 0x800) {
			mood = 2;
		}
	}
	cout << mood;
	system("cls");
	if (mood == 2) return true;
	else return false;
}
