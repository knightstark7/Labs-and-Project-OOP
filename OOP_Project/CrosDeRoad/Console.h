#pragma once
#include "head.h"
class constantVar {
public:
	static bool isMute;
	static bool isHard;
};

static bool isMute = false;

constexpr int ColorCode_DarkWhite	= 7;
constexpr int ColorCode_Cyan		= 11;
constexpr int ColorCode_Red			= 12;
constexpr int ColorCode_Yellow		= 14;
constexpr int ColorCode_White		= 15;
constexpr int default_ColorCode = 7;

constexpr int key_Up	= 1072;
constexpr int key_Down	= 1080;
constexpr int key_Left	= 1075;
constexpr int key_Right = 1077;
constexpr int key_none	= -1;

//define config console command
int inputKey();
void clrscr();
void gotoXY(int column, int line);
int whereX();
int whereY();
void TextColor(int color);
void ShowConsoleCursor(bool showFlag);
void FixConsoleWindow();

//daw text
void drawAlphaC(int x, int y);
void drawAlphaR(int x, int y);
void drawAlphaO(int x, int y);
void drawAlphaS(int x, int y);
void drawAlphaT(int x, int y);
void drawAlphaH(int x, int y);
void drawAlphaE(int x, int y);
void drawAlphaA(int x, int y);
void drawAlphaD(int x, int y);



