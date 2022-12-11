#pragma once
#include "head.h"

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

int inputKey();
//-------------------------Screen-------------------------
void clrscr();
//screen: goto [x,y]
void gotoXY(int column, int line);
//screen: get [x]
int whereX();
//screen: get [y]
int whereY();
void TextColor(int color);
//end----------------------Screen----------------------end
void ShowConsoleCursor(bool showFlag);
void FixConsoleWindow();
void DisableMouse();
class constantVar {
public:
	static bool isMute;
	static bool isHard;
};
void drawTitle();


