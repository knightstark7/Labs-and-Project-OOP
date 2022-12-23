#include "Console.h"

int inputKey() {
	if (_kbhit()) {
		int key = _getch();
		if (key == 224) { // special key
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	else {
		return key_none;
	}
	return key_none;
}

void clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoXY(int abscissa, int ordinate) {
	ShowConsoleCursor(false);
	COORD coord{};
	coord.X = abscissa;
	coord.Y = ordinate;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void drawAlphaC(int column, int line) {
	char alphaC[6][8];
	//row1, row6: 
	for (int i = 2; i < 8; i++) {
		alphaC[0][i] = 1;
		alphaC[5][i] = 1;
	}
	for (int i = 1; i < 5; i++) {
		alphaC[i][0] = 1;
		alphaC[i][1] = 1;

	}
	alphaC[1][2] = 1;
	alphaC[1][3] = 1;
	alphaC[4][2] = 1;
	alphaC[4][3] = 1;

	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (alphaC[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);

}

void drawAlphaT(int column, int line) {
	char alphaT[5][10];
	for (int j = 0; j < 10; j++) {
		alphaT[0][j] = 1;
	}
	for (int i = 0; i < 5; i++) {
		alphaT[i][4] = 1;
		alphaT[i][5] = 1;
	}

	gotoXY(column, line);
	for (int i = 0; i < 5; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 10; j++) {
			if (alphaT[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);
}


void drawAlphaH(int column, int line) {
	char alphaT[5][8];
	for (int j = 2; j < 6; j++) {
		alphaT[2][j] = 1;
	}
	for (int i = 0; i < 5; i++) {
		alphaT[i][0] = 1;
		alphaT[i][1] = 1;
		alphaT[i][6] = 1;
		alphaT[i][7] = 1;
	}

	gotoXY(column, line);
	for (int i = 0; i < 5; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (alphaT[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);
}

void drawAlphaE(int column, int line) {
	char alphaE[5][8];
	for (int j = 0; j < 8; j++) {
		alphaE[0][j] = 1;
		alphaE[4][j] = 1;
	}
	for (int i = 0; i < 5; i++) {
		alphaE[i][0] = 1;
		alphaE[i][1] = 1;
	}
	for (int j = 2; j < 6; j++) {
		alphaE[2][j] = 1;
	}

	gotoXY(column, line);
	for (int i = 0; i < 5; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (alphaE[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);
}


void drawAlphaA(int column, int line) {
	char alphaA[6][8];
	//row1, row6: 
	for (int i = 1; i < 6; i++) {
		alphaA[i][0] = 1;
		alphaA[i][1] = 1;
		alphaA[i][7] = 1;
		alphaA[i][6] = 1;
	}
	for (int j = 2; j < 6; j++) {
		alphaA[0][j] = 1;
		alphaA[3][j] = 1;
	}

	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (alphaA[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);

}

void drawAlphaD(int column, int line) {
	char alphaA[6][8];
	//row1, row6: 
	for (int i = 1; i < 5; i++) {
		alphaA[i][0] = 1;
		alphaA[i][1] = 1;
		alphaA[i][7] = 1;
		alphaA[i][6] = 1;
	}
	for (int j = 0; j < 6; j++) {
		alphaA[0][j] = 1;
		alphaA[5][j] = 1;
	}

	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (alphaA[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);

}

void drawAlphaO(int column, int line) {
	char o[6][10];
	for (int i = 2; i < 8; i++) {
		o[0][i] = 1;
		o[5][i] = 1;
	}
	for (int i = 0; i < 4; i++) {
		o[1][i] = 1;
		o[4][i] = 1;
	}
	for (int i = 6; i < 10; i++) {
		o[1][i] = 1;
		o[4][i] = 1;
	}
	for (int i = 0; i < 2; i++) {
		o[2][i] = 1;
		o[3][i] = 1;
	}
	for (int i = 8; i < 10; i++) {
		o[2][i] = 1;
		o[3][i] = 1;
	}
	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 10; j++) {
			if (o[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);
}
void drawAlphaS(int column, int line) {
	char s[6][8];
	for (int i = 2; i < 8; i++) {
		s[0][i] = 1;
	}
	for (int i = 0; i < 6; i++) {
		s[5][i] = 1;
	}
	s[1][0] = s[1][1] = s[4][6] = s[4][7] = 1;
	for (int i = 0; i < 4; i++) {
		s[2][i] = 1;
	}
	for (int i = 2; i < 8; i++) {
		s[3][i] = 1;
	}
	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 8; j++) {
			if (s[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);
}

void drawAlphaR(int column, int line) {
	char alphaR[6][10];

	for (int i = 0; i < 6; i++) {
		alphaR[i][0] = 1;
		alphaR[i][1] = 1;
	}
	for (int j = 2; j < 6; j++) {
		alphaR[0][j] = 1;
		alphaR[3][j] = 1;
	}
	alphaR[1][6] = alphaR[1][7] = 1;
	alphaR[2][6] = alphaR[2][7] = 1;
	alphaR[4][6] = alphaR[4][7] = 1;
	alphaR[5][8] = alphaR[5][9] = 1;

	gotoXY(column, line);
	for (int i = 0; i < 6; i++) {
		gotoXY(column, line++);
		for (int j = 0; j < 10; j++) {
			if (alphaR[i][j] == 1) {
				TextColor(337);
				cout << ' ';
			}
			else {
				TextColor(7);
				cout << ' ';
			}
		}
		TextColor(7);
		cout << "\n";
	}
	TextColor(7);

}