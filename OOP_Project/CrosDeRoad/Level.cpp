#include "Level.h"

Level::Level() {
	level = 1;
	nEnemy = 0;
	initialize();
}

Level::Level(int level, int nEnemy) {
	this->level = level;
	this->nEnemy = nEnemy;
	initialize();
}

void Level::initialize() {
	//50 is a BIGGGGG number
	int difficulty = 50, maxE = 20;
	if (constantVar::isHard) difficulty = 5, maxE = 40;
	nRow = 10;
	maxEnemy = min(maxE, nRow * 10);
	maxSpeed = difficulty- level * 2;
	minSpeed = difficulty - level * 1;  
}

int Level::getLevel() {
	return level;
}

bool Level::newLevel(int lv) {
	if (lv > maxLevel) return false;
	level = lv;
	nEnemy = 0;
	initialize();
	return true;
}

bool Level::nextLevel() {
	if (level == maxLevel) return false;
	++level;
	nEnemy = 0;
	return true;
}

int Level::getMaxSpeed() {
	return maxSpeed;
}

int Level::getMinSpeed() {
	return minSpeed;
}

Enemy * Level::randNewEnemy(Position pos) {
	if (nEnemy == maxEnemy) return NULL;
	if ((nEnemy < (maxEnemy / 2)) || (rand() % 3)) {
		++nEnemy;
		Enemy * pEnemy = NULL;
		int type = rand() % 4;
		switch (type){
		case 0: {
			pEnemy = new cWorm(pos);
			break;
		}
		case 1: {
			pEnemy = new cCar(pos);
			break;
		}
		case 2: {
			pEnemy = new cFrog(pos);
			break;
		}
		default:
			pEnemy = new cHelicopter(pos);
			break;
		}
		return pEnemy;
	}
	return NULL;
}

Enemy* Level::getNewEnemy(Position pos, int type) {
	++nEnemy;
	Enemy *pEnemy = NULL;
	switch (type){
	case 0: {
		pEnemy = new cWorm(pos);
		break;
	}
	case 1: {
		pEnemy = new cCar(pos);
		break;
	}
	case 2: {
		pEnemy = new cFrog(pos);
		break;
	}
	default:
		pEnemy = new cHelicopter(pos);
		break;
	}
	return pEnemy;
}

void Level::decNEnemy(int d) {
	nEnemy -= d;
}
