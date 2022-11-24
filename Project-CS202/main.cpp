#include "head.h"
#include "Map.h"
#include "Game.h"
#include "cTruck.h"
#include "cCar.h"
#include "cBird.h"

bool constantVar::isMute = false;
bool constantVar::isHard = true;


int main() {
	srand(time(NULL));
	//DisableMouse();
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
	FixConsoleWindow();
	Game game;
	//game.getAllFilename("data");
	game.menu();
	
}