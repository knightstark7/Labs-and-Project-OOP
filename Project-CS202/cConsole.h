#pragma once
#include "headerFile.h"

//static bool isMute = false;
constexpr auto ColorCode_Back		= 0;
constexpr auto ColorCode_DarkBlue	= 1;
constexpr auto ColorCode_DarkGreen	= 2;
constexpr auto ColorCode_DarkCyan	= 3;
constexpr auto ColorCode_DarkRed	= 4;
constexpr auto ColorCode_DarkPink	= 5;
constexpr auto ColorCode_DarkYellow = 6;
constexpr auto ColorCode_DarkWhite	= 7;
constexpr auto ColorCode_Grey		= 8;
constexpr auto ColorCode_Blue		= 9;
constexpr auto ColorCode_Green		= 10;
constexpr auto ColorCode_Cyan		= 11;
constexpr auto ColorCode_Red		= 12;
constexpr auto ColorCode_Pink		= 13;
constexpr auto ColorCode_Yellow		= 14;
constexpr auto ColorCode_White		= 15;

constexpr auto default_ColorCode	= 7;

constexpr auto key_Up	 = 1072;
constexpr auto key_Down  = 1080;
constexpr auto key_Left	 = 1075;
constexpr auto key_Right = 1077;
constexpr auto key_none  = -1;

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