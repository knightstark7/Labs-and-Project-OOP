#include "head.h"
#include "Map.h"
#include "Game.h"
#include "cHelicopter.h"
#include "cCar.h"
#include "cWorm.h"
#include "cFrog.h"

bool constantVar::isMute = false;
bool constantVar::isHard = false;


int main() {
	srand(time(NULL));
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE);
	FixConsoleWindow();
	Game game;
	game.menu();
	
}