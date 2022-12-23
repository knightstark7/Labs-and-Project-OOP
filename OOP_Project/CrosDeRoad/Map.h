#pragma once
#include "head.h"
#include "People.h"
#include "Position.h"
#include "cRows.h"
#include "Level.h"
#include "Enemy.h"

class Map{
	const int length = 115, width = 40;
	char map[45][120];
	People player;
	cRows rowsData;
	Level level;
	int t = 0;
public:
	Map();
	~Map() = default;
	void printMap(); 
	void drawMap(); 
	void redrawMap();
	int draw(Position pos, char ** shape, int w, int h); 
	void deleteOldPlayer();
	void drawPlayer(); 
	void nextState(); 
	void newState();
	void updatePosPeople(char move);
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
