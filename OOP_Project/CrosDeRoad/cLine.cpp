#include "cLine.h"

void cLine::redrawState() {
	if (redLight) {
		TextColor(12);
	}
	else {
		TextColor(10);
	}
	if (direction) {
		gotoXY(RIGHTMAP + 60, currentRow);
	}
	else {
		gotoXY(LEFTMAP - 1, currentRow);
	}
	cout << (char)254;
	TextColor(7);
	for (int i = 0; i < (int)enemy.size(); ++i) {
		Enemy *curEnemy = enemy[i];
		printNewEnemy(curEnemy->getPos(), curEnemy->shape(), curEnemy->getlength(), curEnemy->getwidth());
	}
}

cLine::cLine(int speed, bool direction, bool redLight, int currentRow) {
	this->speed = speed;
	this->direction = direction;
	this->redLight = redLight;
	this->currentRow = currentRow;
	enemy.reserve(100);
}

bool cLine::pushEnemy(Enemy* newEnemy) {
	if (!direction) {
		newEnemy->updatePosition(0, RIGHTMAP - newEnemy->getY());
	}
	if (newEnemy->getY() > RIGHTMAP || newEnemy->getY() <= 3 || (enemy.size() && abs(enemy.back()->getY() - newEnemy->getY()) <= 8)) {
		return false;
	}
	enemy.push_back(newEnemy);
	printNewEnemy(newEnemy->getPos(), newEnemy->shape(), newEnemy->getlength(), newEnemy->getwidth());
	return true;
}

vector<Enemy*> cLine::getEnemy() {
	return enemy;
}

void cLine::toggleRedLight() {
	redLight = !redLight;
}

int cLine::nextState(int t) {
	int nDelete = 0;
	if ((redLight && (rand() % 8 == 0)) || (!redLight && (rand() % 15 == 0)) || (t == 0)) {
		toggleRedLight();
	}
	if (redLight) {
		TextColor(12);
	}
	else {
		TextColor(10);
	}
	if (direction) {
		gotoXY(RIGHTMAP + 60, currentRow);
	}
	else {
		gotoXY(LEFTMAP - 1, currentRow);
	}
	cout << (char)254;
	TextColor(7);
	if (((t % speed) != 0) && t != 0) return nDelete; //test
	if (redLight) return nDelete;
	vector <Enemy*> newEnemy;
	newEnemy.reserve(100);
	for (int i = 0; i < (int)enemy.size(); ++i) {
		Enemy * curEnemy = enemy[i];
		int dy = -1;
		if (direction) dy = 1;
		deleteOldEnemy(curEnemy->getPos(), curEnemy->getlength(), curEnemy->getwidth());
		curEnemy->updatePosition(0, dy);
		// Print Enemy
		bool canPrint = printNewEnemy(curEnemy->getPos(), curEnemy->shape(), curEnemy->getlength(), curEnemy->getwidth()); 
		if (!canPrint) {
			curEnemy->goOutMap();
			++nDelete;
		}
		if (curEnemy->isOutOfMap()) {
			delete curEnemy;
		}
		else {
			newEnemy.push_back(curEnemy);
		}
	}
	enemy = newEnemy;
	return nDelete;
}


void cLine::deleteOldEnemy(Position pos, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFTMAP) return;
	if (Y > RIGHTMAP) return;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHTMAP, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << ' ';
		}
	}
}

bool cLine::printNewEnemy(Position pos, char ** shape, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFTMAP) return 0;
	if (Y > RIGHTMAP) return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHTMAP, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

bool cLine::getDirection() {
	return direction;
}

bool cLine::getRedLight() {
	return redLight;
}

int cLine::getSpeed() {
	return speed;
}

int cLine::getCurrentRow() {
	return currentRow;
}