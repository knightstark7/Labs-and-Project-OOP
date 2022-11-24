#pragma once
#include "headerFile.h"

class cOneRow {
private:
	vector <cEnemy*> enemy;
	bool direction; //0: to the left, 1: to the right
	bool redLight = false;
	int speed;
	int currentRow;
public:
	cOneRow() = default;
	cOneRow(int speed, bool direction, bool redLight, int currentRow);
	~cOneRow() = default;
	bool pushEnemy(cEnemy* newEnemy); // push a new new enemy, if !position => set base on direction
	int moveToNextState(int t); // if % speed = 0, move all enemy left or right base on direction && redLight
	void redrawState();
	void toggleRedLight();
	void deleteOldEnemy(cPosition pos, int w, int h);
	bool printNewEnemy(cPosition pos, char ** shape, int w, int h);
	vector<cEnemy*> getEnemy();
	bool getDirection();
	bool getRedLight();
	int getSpeed();
	int getCurrentRow();
};

#endif // cOneRow