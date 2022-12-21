#pragma once
#include "head.h"
#include "People.h"
#include "Position.h"
#include "cRows.h"
#include "Level.h"
#include "Enemy.h"

class Map{
	const int length = 115, width = 40;
	char map[44][125];
	People player;
	cRows rowsData;
	Level level;
	int t = 0;
public:
	Map();
	~Map() = default;
	void printMap(); // print map to screen
	void drawMap(); // draw all enemies and player
	void redrawMap();
	int draw(Position pos, char ** shape, int w, int h); // draw from position pos(x, y) shape(w, h) | 1: ok, 0: go out of map, -1: crash
	void deleteOldPlayer();
	void drawPlayer(); // draw player to map, check if crash => kill player
	void nextState(); // generate new enemies base on level and push to rows
	void newState(); // intialize a new map base on level, reset player state
							   //    void handleKeyInput(); // receive key input from Game and call appropriate function
	void updatePosPeople(char moving);
	void printChurch();
	void saveGame(string file);
	bool loadGame(string file);
	void printBorder();
	void printCongratulation();
	bool printLevelUp();
	bool isEnd();
	bool isWin();
	void nextLevel();
	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};
