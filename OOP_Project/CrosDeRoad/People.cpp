#include "People.h"

People::People() : isDead(false) {
	pos.setPos(34, 28);
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++) {
		a[i] = new char[5];
	}
	char b[3][6] = { "||||/",
				   "(o o)",
				   "-(_)-" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = b[i][j];
		}
	}
	a[0][0] = char(92);
}

People::People(Position pos) : isDead(false), pos(pos) {
	a = new char* [3];
	emptyPlayer = new char* [3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++) {
		a[i] = new char[5];
	}
	char b[3][6] = { "||||/",
				   "(o o)",
				   "-(_)-" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = b[i][j];
		}
	}
	a[0][0] = char(92);
}

People::~People()
{
	for (int i = 0; i < 3; i++) {
		delete[] a[i];
		delete[] emptyPlayer[i];
	}
	delete[] a;
	delete[] emptyPlayer;
}

void People::killPlayer() {
	isDead = true;
}

char ** People::shape() {
	return a;
}

char **People::emptyShape() {
	return emptyPlayer;
}

Position People::getPos() {
	return pos;
}

int People::getX() {
	return pos.getX();
}

int People::getY() {
	return pos.getY();
}

int People::getwidth() {

	return width;

}

int People::getlength() {

	return length ;

}

void People::Up() {
	sound();
	if (pos.getX() <= 3) return;
	pos.setPos(pos.getX() - 3, pos.getY());
}

void People::Down() {
	sound();
	if (pos.getX() + 3 > 34) return;
	pos.setPos(pos.getX() + 3, pos.getY());
}

void People::Left() {
	sound();
	if (pos.getY() <= LEFTMAP) return;
	pos.setPos(pos.getX(), pos.getY() - 1);
}

void People::Right() {
	sound();
	if (pos.getY() + 2 >= RIGHTMAP) return;
	pos.setPos(pos.getX(), pos.getY() + 1);
}

bool People::checkIsDead() {
	return isDead;
}

bool People::crash(Position pos, int w, int h) {
	int magicConst = 3;
	if (h == 5) {
		//crash while Car/Truck on the right
		magicConst = 3;
		if (this->getX() == pos.getX()) {
			if (this->getY() <= pos.getY() && max(getY(), pos.getY()) <= min(getY() + getlength() - magicConst, pos.getY() + w - magicConst))
			{
				return true;
			}
			if (this->getY() >= pos.getY() && getY() - pos.getY() <= 3)
				return true;
		}
	}
	if (h == 3) {
		magicConst = 1;
		if (this->getX() == pos.getX())
		{
			if (this->getY() >= pos.getY() && pos.getY() + w - magicConst >= this->getY())
			{
				return true;
			}
			if (getY() <= pos.getY() && pos.getY() - getY() <= 2)
				return true;
		}
	}
	else
		if (this->getX() == pos.getX() && max(getY(), pos.getY()) <= min(getY() + getlength() - magicConst, pos.getY() + w - magicConst)) {
			return true;
		}
	return false;
}


void People::sound()
{
	if(!constantVar::isMute && !isDead)
	PlaySound(TEXT("Jump.wav"), NULL, SND_ASYNC);
}
