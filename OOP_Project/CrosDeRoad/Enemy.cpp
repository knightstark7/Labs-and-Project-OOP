#include "Enemy.h"

Enemy::Enemy() : outMap(false) {}

Enemy::Enemy(Position pos) : point(pos), outMap(false) {}

Position Enemy::getPos() {
	return point;
}

int Enemy::getX() {
	return point.getX();
}

int Enemy::getY() {
	return point.getY();
}

bool Enemy::isOutOfMap() {

	return outMap;

}

void Enemy::goOutMap() {

	outMap = true;

}

int Enemy::getlength() {

	return 5;

}

int Enemy::getwidth() {

	return 3;

}

void Enemy::updatePosition(int dx, int dy) {
	point.setPos(point.getX() + dx, point.getY() + dy);
}

