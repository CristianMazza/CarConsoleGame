#include "map.h"

map::map() {
	width = 24;
	height = 20;
}

void map::draw() {
	for (short j = 1; j < height; j++) {
		for (short i = 1; i < width; i++) {
			consolez.gotoconsole(1, j);
			cout << "|";
			if (i == width - 1) {
				consolez.gotoconsole(i, j);
				cout << "|";
			}
			else if (j == height-1) {
				consolez.gotoconsole(i, j);
				cout << "_";
			}
		}
	}
}


void map::setConsole(console a) {
	consolez = a;
} 

int map::getwidth() {
	return width;
}

int map::getheight() {
	return height;
}

