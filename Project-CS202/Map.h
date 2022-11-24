#pragma once
#include "head.h"
#include "People.h"
#include "cPosition.h"
#include "cRows.h"
#include "cLevel.h"
#include "Enemy.h"

using namespace std;
class Map{
	const int length = 115, width = 40;
	char map[44][125];
	People player;
	cRows rowsData;
	cLevel level;
	int t = 0;
public:
	Map();
	~Map() = default;
//	void resetMap(); // reset the map to default with no enemy and no player
	void printMap(); // print map to screen
	void drawMap(); // draw all enemies and player
	void redrawMap();
	int draw(cPosition pos, char ** shape, int w, int h); // draw from position pos(x, y) shape(w, h) | 1: ok, 0: go out of map, -1: crash
	void deleteOldPlayer();
	void drawPlayer(); // draw player to map, check if crash => kill player
//	void drawEnemies(Enemy * enemy); // draw enemy to map
	void randomNextState(); // generate new enemies base on level and push to rows
	void initializeNewState(); // intialize a new map base on level, reset player state
							   //    void handleKeyInput(); // receive key input from Game and call appropriate function
	void updatePosPlayer(char moving);

	void bombEffect();

	void saveGame(string file);
	bool loadGame(string file);

	void printBorder();

	void printCongrats();
	bool printLevelUp();
	//check endgame
	bool isEnd();
	//check isWin
	bool isWin();
	void nextLevel();

	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};
