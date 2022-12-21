#pragma once
#include "head.h"
#include "Position.h"
#include "Enemy.h"
#include "cWorm.h"
#include "cCar.h"
#include "cFrog.h"
#include "cHelicopter.h"

class Level{
private:
	int level;
	int maxEnemy, minSpeed, maxSpeed, nEnemy;
	int nRow;
	const int maxLevel = 5;
	void initialize();
public:
	Level();
	Level(int level, int enemy);
	~Level() =  default;
	int getLevel();
	bool newLevel(int lv);
	bool nextLevel();
	int getMaxSpeed();
	int getMinSpeed();
	Enemy *randNewEnemy(Position pos);
	Enemy *getNewEnemy(Position pos, int type);
	void decNEnemy(int de);
};

