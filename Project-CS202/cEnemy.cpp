#include "cEnemy.h"

cEnemy::cEnemy() : outMap(false) {}

cEnemy::cEnemy(cPosition pos) : point(pos), outMap(false) {}

cPosition cEnemy::getPos() {
	return point;
}

int cEnemy::getX() {
	return point.getX();
}

int cEnemy::getY() {
	return point.getY();
}

bool cEnemy::isOutOfMap() {
	return outMap;
}

void cEnemy::goOutMap() {
	outMap = true;
}

int cEnemy::getWidth() {
	return 5;
}

int cEnemy::getHeight() {
	return 3;
}

void cEnemy::updatePosition(int dx, int dy) {
	point.setPos(point.getX() + dx, point.getY() + dy);
}
