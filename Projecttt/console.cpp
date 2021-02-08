#include "console.h"

console::console() {
	consolehand = GetStdHandle(STD_OUTPUT_HANDLE);
}

void console::gotoconsole(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(consolehand, pos);
}

void console::message1() {
	setWindow();
	gotoconsole(30, 5);
	cout << "BENVENUTO!";
	gotoconsole(10, 7);
	cout << "QUESTO GIOCO E' STATO CREATO DA CRISTIAN MAZZA";
	gotoconsole(10, 8);
	cout << "COME PROGETTO DI PROGRAMMAZIONE DELL' A.A. 2019/2020";
	gotoconsole(10, 9);
	cout << "DELL'UNIVERSITA' ALMA MATER STUDIORUM DI BOLOGNA.";
	Sleep(6000);
	system("cls");
}

void console::message2(){
	setWindow();
	gotoconsole(30, 3);
	cout << "REGOLE DEL GIOCO:";
	gotoconsole(4, 5);
	cout << "SEI UN' AUTO. IL TUO SCOPO E' DI EVITARE GLI OSTACOLI";
	gotoconsole(4, 6);
	cout << "IN MODO DA AUMENTARE IL TUO PUNTEGGIO. SI PARTE DA 10 PUNTI.";
	gotoconsole(4, 7);
	cout << "IL GIOCO TERMINA UNA VOLTA CHE SI SCENDE A 0 PUNTI.";
	gotoconsole(4, 8);
	cout << "- SE SUPERI UN OSTACOLO INCREMENTI DI 10 PUNTI";
	gotoconsole(4, 9);
	cout << "- SE TI SCONTRI CON UN OSTACOLO O VAI FUORI STRADA DECREMENTI DI 30 PUNTI";
	gotoconsole(5, 10);
	cout << "OGNI 200 PUNTI SALI DI LIVELLO FINO AD UN MASSIMO DI 10 LIVELLI.";
	gotoconsole(5, 11);
	cout << "E' PRESENTE IL TURBO, INDICATO CON IL SIMBOLO '$'";
	gotoconsole(5, 12);
	cout << "IL TURBO VALE DA 1 A 9 E INDICANO GLI OSTACOLI";
	gotoconsole(5, 13);
	cout << "CHE PUOI COLPIRE SENZA SCENDERE DI PUNTEGGIO.";
	gotoconsole(5, 14);
	cout << "UNA VOLTA ATTIVATO IL TURBO, LA TUA AUTO SARA' COLORATA DI VERDE.";
	gotoconsole(5, 15);
	cout << "PER SPOSTARE L'AUTO USA LA FRECCIA DESTRA O SINISTRA DELLA TASTIERA.";
	gotoconsole(5, 17);
	cout << "COSA ASPETTI? PREMI ENTER PER INIZIARE UNA PARTITA!";
	bool flag = true;
	while (flag) {
		if (GetKeyState(VK_RETURN) & 0x800) flag = false;
	}
	Sleep(500);
	system("cls");
	setWindow();
}

void console::countdown() {
	system("cls");
	setWindow();
	gotoconsole(40,10);
	cout << "3";
	Sleep(1000);
	system("cls");
	setWindow();
	gotoconsole(40,10);
	cout << "2";
	Sleep(1000);
	system("cls");
	setWindow();
	gotoconsole(40,10);
	cout << "1";
	Sleep(1000);
	system("cls");
	setWindow();
	gotoconsole(40,10);
	cout << "VIA!";
	setWindow();
	Sleep(500);
	system("cls");
	setWindow();
}

void console::ShowConsoleCursor(bool flag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = flag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void console::setGreenColor(bool flag) {
	if (flag == true) SetConsoleTextAttribute(consolehand, 10);
	else SetConsoleTextAttribute(consolehand, 7);
}

void console::setWindow() {
	for (short j = 0; j < 21; j++) {
		for (short i = 0; i < 80; i++) {
			if (j == 0 && i > 0) {
				gotoconsole(i, j);
				cout << "#";
			}
			if (i == 0) {
				gotoconsole(i, j);
				cout << "#";
			}
			if (i == 79) {
				gotoconsole(i, j);
				cout << "#";
			}
			if (j == 20) {
				gotoconsole(i, j);
				cout << "#";
			}
		}
	}
}