#pragma once
#include "head.h"
#include "cPosition.h"
#include "Enemy.h"
#include "cWorm.h"
#include "cCar.h"
#include "cFrog.h"
#include "cHelicopter.h"

class cLevel{
private:
	int level;
	int maxEnemy, minSpeed, maxSpeed, nEnemy;
	int nRow;
	const int maxLevel = 5;
	//  int nColumn;
	void initialize();
public:
	cLevel();
	cLevel(int level, int nEnemy);
	//  ~cLevel();
	int getLevel();
	bool newLevel(int lv);
	bool nextLevel();
	int getMaxSpeed();
	int getMinSpeed();
	Enemy *randNewEnemy(cPosition pos);
	Enemy *getNewEnemy(cPosition pos, int type);
	void decNEnemy(int d);
};

