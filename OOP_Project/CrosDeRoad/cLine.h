#pragma once
#include "head.h"
#include "Enemy.h"

class cLine{
private:
	vector <Enemy*> enemy;
	bool direction; //0: left, 1: right of map
	bool redLight = false;
	int speed;
	int currentRow;
public:
	cLine() = default;
	cLine(int speed, bool direction, bool redLight, int currentRow);
	~cLine() = default;
	bool pushEnemy(Enemy* newEnemy);
	int nextState(int t);
	void redrawState();
	void toggleRedLight();
	void deleteOldEnemy(Position pos, int w, int h);
	bool printNewEnemy(Position pos, char ** shape, int w, int h);
	vector<Enemy*> getEnemy();
	bool getDirection();
	bool getRedLight();
	int getSpeed();
	int getCurrentRow();
};

