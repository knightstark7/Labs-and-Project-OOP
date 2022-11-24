#include "cOneRow.h"

void cOneRow::redrawState() {
	if (redLight) {
		TextColor(12);
	}
	else {
		TextColor(10);
	}
	if (direction)
	{
		gotoXY(RIGHTMAP + 60, currentRow);
	}
	else
	{
		gotoXY(LEFTMAP - 1, currentRow);
	}
	cout << (char)254;
	TextColor(7);
	for (int i = 0; i < (int)enemy.size(); ++i) {
		cEnemy * curEnemy = enemy[i];
		printNewEnemy(curEnemy->getPos(), curEnemy->shape(), curEnemy->getWidth(), curEnemy->getHeight());
	}
}

cOneRow::cOneRow(int speed, bool direction, bool redLight, int currentRow) {
	this->speed = speed;
	this->direction = direction;
	this->redLight = redLight;
	this->currentRow = currentRow;
	enemy.reserve(100);
}

bool cOneRow::pushEnemy(cEnemy* newEnemy) {
	if (!direction) {
		newEnemy->updatePosition(0, RIGHTMAP - newEnemy->getY());
	}
	if (newEnemy->getY() > RIGHTMAP || newEnemy->getY() <= 3 || (enemy.size() && abs(enemy.back()->getY() - newEnemy->getY()) <= 8)) {
		return false;
	}
	enemy.push_back(newEnemy);
	printNewEnemy(newEnemy->getPos(), newEnemy->shape(), newEnemy->getWidth(), newEnemy->getHeight());
	return true;
}

vector<cEnemy*> cOneRow::getEnemy() {
	return enemy;
}

void cOneRow::toggleRedLight() {
	redLight = !redLight;
}

int cOneRow::moveToNextState(int t) {
	int nDelete = 0;
	if ((redLight && (rand() % 8 == 0)) || (!redLight && (rand() % 15 == 0)) || (t == 0)) {
		toggleRedLight();
		// Display Traffic Light
		//
	}
	if (redLight) {
		TextColor(12);
	}
	else {
		TextColor(10);
	}
	if (direction)
	{
		gotoXY(RIGHTMAP + 60, currentRow);
	}
	else
	{
		gotoXY(LEFTMAP - 1, currentRow);
	}
	cout << (char)254;
	TextColor(7);
	if (((t % speed) != 0) && t != 0) return nDelete; //test
	if (redLight) return nDelete;
	vector <cEnemy*> newEnemy;
	newEnemy.reserve(100);
	for (int i = 0; i < (int)enemy.size(); ++i) {
		cEnemy * curEnemy = enemy[i];
		int dy = -1;
		if (direction) dy = 1;
		deleteOldEnemy(curEnemy->getPos(), curEnemy->getWidth(), curEnemy->getHeight());
		curEnemy->updatePosition(0, dy);
		// Print Enemy
		bool canPrint = printNewEnemy(curEnemy->getPos(), curEnemy->shape(), curEnemy->getWidth(), curEnemy->getHeight()); 
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


void cOneRow::deleteOldEnemy(cPosition pos, int w, int h) {
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

bool cOneRow::printNewEnemy(cPosition pos, char ** shape, int w, int h) {
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

bool cOneRow::getDirection() {
	return direction;
}

bool cOneRow::getRedLight() {
	return redLight;
}

int cOneRow::getSpeed() {
	return speed;
}

int cOneRow::getCurrentRow() {
	return currentRow;
}