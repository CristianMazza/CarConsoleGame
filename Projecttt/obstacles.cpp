#include "obstacles.h"

obstacles::obstacles() {
	p = NULL;
	last = NULL;
	n = 100;
	timex = clock();
	mood = 0;
	collision = false;
	gamez = NULL;
}

void obstacles::listObstacles() {
	while (n > 0) {
		addElement();
	}
}

void obstacles::addElement() {
	if (n > 0) {
		if (p == NULL) srand(time(NULL));
		string str;
		int m = rand() % 13;
		switch (m) {
		case 0:
			str = "00K00";
			break;
		case 1:
			str = "$";
			break;
		case 2:
			str = "00M00";
			break;
		case 3:
			str = 'A' + rand() % 26;
			break;
		case 4:
			str = "00G00";
			break;
		case 5:
			str = 'A' + rand() % 26;
			break;
		case 6:
			str = 'A' + rand() % 26;
			break;
		case 7:
			str = "00B00";
			break;
		case 8:
			str = 'A' + rand() % 26;
			break;
		case 9:
			str = 'A' + rand() % 26;
			break;
		case 10:
			str = "00L00";
			break;
		case 11:
			str = "00E00";
			break;
		case 12:
			str = "00Z00";
			break;
		}
		n = n - 1;
		if (p == NULL) {
			p = new obstacle();
			p->isVisible = false;
			p->yobs = 0;
			p->str = str;
			p->next = NULL;
			if (str.size() > 1) p->xobs = (rand() % (mapz.getwidth() - 5)) + 2;
			else p->xobs = (rand() % (mapz.getwidth() - 3)) + 2;
		}
		else {
			ptr_lista tmp = p;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = new obstacle();
			tmp->next->str = str;
			tmp->next->yobs = 0;
			tmp->next->isVisible = false;
			tmp->next->next = NULL;
			last = tmp->next;
			if (str.size() > 1) tmp->next->xobs = (rand() % (mapz.getwidth() - 5)) + 2;
			else tmp->next->xobs = (rand() % (mapz.getwidth() - 3)) + 2;
		}
		decNumber();
	}
}


void obstacles::drawObstacle() {
	ptr_lista tmp = p;
	while (tmp->isVisible == true) {
		tmp = tmp->next;
	}
	tmp->isVisible = true;
	tmp->yobs = tmp->yobs + 1;
	if (tmp->str.size() > 1) {
		consolez.gotoconsole(tmp->xobs+1, tmp->yobs);
		cout << tmp->str[0];
	}
	else {
		consolez.gotoconsole(tmp->xobs, tmp->yobs);
		cout << tmp->str;
	}

}

void obstacles::goDownObstacle() {
	ptr_lista tmp = p;
	while (tmp->isVisible == true) {
		tmp->yobs = tmp->yobs + 1;
		if (tmp->str.size() > 1) {
			if (tmp->yobs > 3) {
				consolez.gotoconsole(tmp->xobs+1, tmp->yobs - 3);
				cout << " ";
			}
			if (tmp->yobs > 2) {
				consolez.gotoconsole(tmp->xobs, tmp->yobs - 2);
				cout << " " << tmp->str[0] << " ";
			}
			consolez.gotoconsole(tmp->xobs, tmp->yobs - 1);
			cout << tmp->str[1] << tmp->str[2] << tmp->str[3];
			consolez.gotoconsole(tmp->xobs+1, tmp->yobs);
			cout << tmp->str[4];
		}
		else {
			consolez.gotoconsole(tmp->xobs, tmp->yobs - 1);
			cout << " ";
			consolez.gotoconsole(tmp->xobs, tmp->yobs);
			cout << tmp->str;
		}
		tmp = tmp->next;
	}
	setCollision(false);
}

void obstacles::ObsController() {
	double duration = (clock() - timex) / (double)CLOCKS_PER_SEC;
	if (gamez->getTurbo() > 0) {
		if ((duration > 0.25 && mood == 0) || (duration > 0.5 && mood == 1) || (duration > 0.75 && mood == 2) || (duration > 1)) {
			mood = mood + 1;
			goDownObstacle();
			if (mood >= 3) {
				drawObstacle();
				TimeInit();
				mood = 0;
			}
		}
	}
	else {
		switch (gamez->getLevel()) {
		case 1:
			if ((duration > 0.9 && mood == 0) || (duration > 1.8 && mood == 1) || (duration > 2.7 && mood == 2) || (duration > 3.6 && mood == 3) || (duration > 4.5)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 4) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 2:
			if ((duration > 0.8 && mood == 0) || (duration > 1.6 && mood == 1) || (duration > 2.4 && mood == 2) || (duration > 3.2 && mood == 3) || (duration > 4)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 4) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 3:
			if ((duration > 0.7 && mood == 0) || (duration > 1.4 && mood == 1) || (duration > 2.1 && mood == 2) || (duration > 2.8 && mood == 3) || (duration > 3.5)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 4) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 4:
			if ((duration > 0.5 && mood == 0) || (duration > 1 && mood == 1) || (duration > 1.5 && mood == 2) || (duration > 2 && mood == 3) || (duration > 2.5)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 5:
			if ((duration > 0.5 && mood == 0) || (duration > 1 && mood == 1) || (duration > 1.5 && mood == 2) || (duration > 2)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 6:
			if ((duration > 0.45 && mood == 0) || (duration > 0.9 && mood == 1) || (duration > 1.35 && mood == 2) || (duration > 1.8)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 7:
			if ((duration > 0.4 && mood == 0) || (duration > 0.8 && mood == 1) || (duration > 1.2 && mood == 2) || (duration > 1.6)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 8:
			if ((duration > 0.35 && mood == 0) || (duration > 0.7 && mood == 1) || (duration > 1.05 && mood == 2) || (duration > 1.4)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 9:
			if ((duration > 0.3 && mood == 0) || (duration > 0.6 && mood == 1) || (duration > 0.9 && mood == 2) || (duration > 1.2)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		case 10:
			if ((duration > 0.25 && mood == 0) || (duration > 0.5 && mood == 1) || (duration > 0.75 && mood == 2) || (duration > 1)) {
				mood = mood + 1;
				goDownObstacle();
				if (mood >= 3) {
					drawObstacle();
					TimeInit();
					mood = 0;
				}
			}
			break;
		}
	}
}

void obstacles::checkCollisionFirstObstacle(int x, int y) {
	ptr_lista tmp = p;
	if (p->str.length() > 1) {
		if ((p->yobs == y - 2 && p->xobs == x) || (p->yobs == y - 1 && p->xobs + 1 == x) || (p->yobs == y - 1 && p->xobs + 1 == x + 2) || (p->yobs == y && p->xobs + 2 == x) || (p->yobs == y && p->xobs == x + 2) || (p->yobs - 1 == y && p->xobs + 2 == x + 1) || (p->yobs - 1 == y && p->xobs == x + 1) || (p->yobs - 2 == y && p->xobs == x)) {
			if (p->yobs == y - 2 && p->xobs == x) {
				consolez.gotoconsole(p->xobs, p->yobs - 1);
				cout << "   ";
				consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
				cout << " ";
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "X";
				}
			}
			else if (p->yobs == y - 1 && p->xobs + 1 == x) {
				consolez.gotoconsole(p->xobs, p->yobs - 1);
				cout << "  *";
				consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
				cout << " ";
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "X";
				}
			}
			else if ((p->yobs == y - 1) && (p->xobs + 1 == x + 2)) {
				consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
				cout << " ";
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "*  ";
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "X  ";
					consolez.gotoconsole(p->xobs + 1, p->yobs);
					cout << "X";
				}
			}
			else if (p->yobs == y && p->xobs + 2 == x) {
				consolez.gotoconsole(p->xobs + 1, p->yobs);
				cout << " ";
				consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
				cout << " ";
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "  *";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "  X";
				}
			}
			else if (p->yobs == y && p->xobs == x + 2) {
				consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
				cout << " ";
				consolez.gotoconsole(p->xobs + 1, p->yobs);
				cout << " ";
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "*  ";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "X  ";
				}

			}
			else if (p->yobs - 1 == y && p->xobs + 2 == x + 1) {
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(false);
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "  *";
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs, p->yobs - 1);
					cout << "  X";
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "X";
				}
			}
			else if (p->yobs - 1 == y && p->xobs == x + 1) {
				consolez.gotoconsole(p->xobs, p->yobs - 1);
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					cout << "*  ";
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					cout << "X  ";
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "X";
				}
			}
			else if (p->yobs - 2 == y && p->xobs == x) {
				if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "*";
					consolez.setGreenColor(false);
				}
				else {
					consolez.gotoconsole(p->xobs + 1, p->yobs - 2);
					cout << "X";
				}
			}
			deleteObstacle(p);
			if (gamez->getTurbo() > 0) {
				setCollision(false);
				gamez->incScore();
				gamez->printScore();
				gamez->decTurbo();
				gamez->printTurbo();
				if (gamez->getTurbo() == 0) {
					gamez->getMax_pt();
					Sleep(1000);
				}
			}
			else {
				setCollision(true);
				gamez->decScore();
				gamez->printScore();
			}
			gamez->printLevel();
			n = n + 1;
			addElement();
		}
		else if (p->yobs == y + 1 || p->yobs == y + 2 || p->yobs == y + 3) {
			if (p->yobs == y + 1) {
				consolez.gotoconsole(p->xobs + 1, p->yobs);
				cout << "_";
			}
			else if (p->yobs == y + 2) {
				consolez.gotoconsole(p->xobs + 1, p->yobs);
				cout << "#";
				consolez.gotoconsole(p->xobs, p->yobs - 1);
				cout << "___";
			}
			else {
				consolez.gotoconsole(p->xobs + 1, p->yobs);
				cout << " ";
				consolez.gotoconsole(p->xobs, p->yobs - 1);
				cout << "###";
				consolez.gotoconsole(p->xobs, p->yobs - 2);
				cout << "___";
				deleteObstacle(p);
				gamez->incScore();
				gamez->printScore();
				gamez->getMax_pt();
				setCollision(false);
				if (gamez->getTurbo() > 0) {
					gamez->decTurbo();
					gamez->printTurbo();
					if (gamez->getTurbo() == 0) Sleep(1000);
				}
				n = n + 1;
				addElement();
				gamez->printLevel();
			}
		}
	}
	else {
		if ((p->yobs == y - 2 && p->xobs == x + 1) || (p->yobs == y - 1 && p->xobs == x) || (p->yobs == y - 1 && p->xobs == x + 2) || (p->yobs == y && p->xobs == x + 1)) {
			if (p->str == "$") {
				consolez.gotoconsole(p->xobs, p->yobs);
				cout << "*";
				deleteObstacle(p);
				setCollision(false);
				gamez->setFirstTurbo(true);
				gamez->startTurbo();
				gamez->printTurbo();
				Sleep(1000);
			}
			else if (gamez->getTurbo() > 0) {
				consolez.setGreenColor(true);
				consolez.gotoconsole(p->xobs, p->yobs);
				cout << "*";
				consolez.setGreenColor(false);
				deleteObstacle(p);
				setCollision(false);
				gamez->incScore();
				gamez->printScore();
				gamez->decTurbo();
				gamez->printTurbo();
				if (gamez->getTurbo() == 0) {
					gamez->getMax_pt();
					Sleep(1000);
				}
				}
				else {
					consolez.gotoconsole(p->xobs, p->yobs);
					cout << "X";
					deleteObstacle(p);
					setCollision(true);
					gamez->decScore();
					gamez->printScore();
					gamez->printLevel();
				}
			n = n + 1;
			addElement();
			}
			else if (p->yobs == y + 1) {
				consolez.gotoconsole(p->xobs, p->yobs);
				cout << "_";
				deleteObstacle(p);
				setCollision(false);
				gamez->incScore();
				gamez->printScore();
				gamez->printLevel();
				gamez->getMax_pt();
				if (gamez->getTurbo() > 0) {
					gamez->decTurbo();
					gamez->printTurbo();
					if (gamez->getTurbo() == 0) Sleep(1000);
				}
				n = n + 1;
				addElement();
			}
		}
	}

	void obstacles::checkCollisionSecondObstacle(int x, int y) {
		ptr_lista tmp = p;
		if (p->next->str.length() > 1) {
			if ((p->next->yobs == y - 2 && p->next->xobs == x) || (p->next->yobs == y - 1 && p->next->xobs + 1 == x) || (p->next->yobs == y - 1 && p->next->xobs + 1 == x + 2) || (p->next->yobs == y && p->next->xobs + 2 == x) || (p->next->yobs == y && p->next->xobs == x + 2) || (p->next->yobs - 1 == y && p->next->xobs + 2 == x + 1) || (p->next->yobs - 1 == y && p->next->xobs == x + 1) || (p->next->yobs - 2 == y && p->next->xobs == x)) {
				if (p->next->yobs == y - 2 && p->next->xobs == x) {
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
					cout << "   ";
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
					cout << " ";
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "X";
					}
				}
				else if (p->next->yobs == y - 1 && p->next->xobs + 1 == x) {
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
					cout << "  *";
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
					cout << " ";
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "X";
					}
				}
				else if ((p->next->yobs == y - 1) && (p->next->xobs + 1 == x + 2)) {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
					cout << " ";
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "*  ";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "X  ";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
						cout << "X";
					}
				}
				else if (p->next->yobs == y && p->next->xobs + 2 == x) {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
					cout << " ";
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
					cout << " ";
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "  *";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "  X";
					}
				}
				else if (p->next->yobs == y && p->next->xobs == x + 2) {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
					cout << " ";
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
					cout << " ";
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "*  ";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "X  ";
					}

				}
				else if (p->next->yobs - 1 == y && p->next->xobs + 2 == x + 1) {
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(false);
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "  *";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
						cout << "  X";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "X";
					}
				}
				else if (p->next->yobs - 1 == y && p->next->xobs == x + 1) {
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						cout << "*  ";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						cout << "X  ";
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "X";
					}
				}
				else if (p->next->yobs - 2 == y && p->next->xobs == x) {
					if (gamez->getTurbo() > 0) {
						consolez.setGreenColor(true);
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "*";
						consolez.setGreenColor(false);
					}
					else {
						consolez.gotoconsole(p->next->xobs + 1, p->next->yobs - 2);
						cout << "X";
					}
				}
				deleteObstacle(p->next);
				if (gamez->getTurbo() > 0) {
					setCollision(false);
					gamez->incScore();
					gamez->printScore();
					gamez->decTurbo();
					gamez->printTurbo();
					if (gamez->getTurbo() == 0) {
						gamez->getMax_pt();
						Sleep(1000);
					}
				}
				else {
					setCollision(true);
					gamez->decScore();
					gamez->printScore();
				}
				gamez->printLevel();
				n = n + 1;
				addElement();
			}
			else if (p->next->yobs == y + 1 || p->next->yobs == y + 2 || p->next->yobs == y + 3) {
				if (p->next->yobs == y + 1) {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
					cout << "_";
				}
				else if (p->next->yobs == y + 2) {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
					cout << "#";
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
					cout << "___";
				}
				else {
					consolez.gotoconsole(p->next->xobs + 1, p->next->yobs);
					cout << " ";
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 1);
					cout << "###";
					consolez.gotoconsole(p->next->xobs, p->next->yobs - 2);
					cout << "___";
					deleteObstacle(p->next);
					setCollision(false);
					gamez->incScore();
					gamez->printScore();
					gamez->getMax_pt();
					if (gamez->getTurbo() > 0) {
						gamez->decTurbo();
						gamez->printTurbo();
						if (gamez->getTurbo() == 0) Sleep(1000);
					}
					n = n + 1;
					addElement();
					gamez->printLevel();
				}
			}
		}
		else {
			if ((p->next->yobs == y - 2 && p->next->xobs == x + 1) || (p->next->yobs == y - 1 && p->next->xobs == x) || (p->next->yobs == y - 1 && p->next->xobs == x + 2) || (p->next->yobs == y && p->next->xobs == x + 1)) {
				if (p->next->str == "$") {
					consolez.gotoconsole(p->next->xobs, p->next->yobs);
					cout << "*";
					deleteObstacle(p->next);
					setCollision(false);
					gamez->setFirstTurbo(true);
					gamez->startTurbo();
					gamez->printTurbo();
					Sleep(1000);
				}
				else if (gamez->getTurbo() > 0) {
					consolez.setGreenColor(true);
					consolez.gotoconsole(p->next->xobs, p->next->yobs);
					cout << "*";
					consolez.setGreenColor(false);
					deleteObstacle(p->next);
					setCollision(false);
					gamez->incScore();
					gamez->printScore();
					gamez->decTurbo();
					gamez->printTurbo();
					if (gamez->getTurbo() == 0) {
						gamez->getMax_pt();
						Sleep(1000);
					}
				}
				else {
					consolez.gotoconsole(p->next->xobs, p->next->yobs);
					cout << "X";
					deleteObstacle(p->next);
					setCollision(true);
					gamez->decScore();
					gamez->printScore();
					gamez->printLevel();
				}
				n = n + 1;
				addElement();
			}
			else if (p->next->yobs == y + 1) {
				consolez.gotoconsole(p->next->xobs, p->next->yobs);
				cout << "_";
				deleteObstacle(p->next);
				setCollision(false);
				gamez->incScore();
				gamez->printScore();
				gamez->printLevel();
				gamez->getMax_pt();
				if (gamez->getTurbo() > 0) {
					gamez->decTurbo();
					gamez->printTurbo();
					if (gamez->getTurbo() == 0) Sleep(1000);
				}
				n = n + 1;
				addElement();
			}
		}
	}


void obstacles::setCollision(bool coll) {
	collision = coll;
}

bool obstacles::getCollision() {
	return collision;
}

void obstacles::deleteObstacle(ptr_lista p_delete) {
	if (p == p_delete) {
		p = p->next;
		delete p_delete;
		p_delete = NULL;
	}
	else {
		p->next = p->next->next;
		delete p_delete;
		p_delete = NULL;
	}
}


void obstacles::TimeInit() {
	timex = clock();
}

void obstacles::setConsole(console a) {
	consolez = a;
}

void obstacles::setMap(map a) {
	mapz = a;
}

void obstacles::setGame(game *a) {
	gamez = a;
}

int obstacles::getNumber() {
	return n;
}

void obstacles::decNumber() {
	n = n - 1;
}