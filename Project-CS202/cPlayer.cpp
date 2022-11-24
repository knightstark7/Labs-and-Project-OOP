#include "cPlayer.h"

cPlayer::cPlayer() : isDead(false) {
	pos.setPos(34, 28);
	a = new char*[3];
	emptyPlayer = new char*[3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++){
		a[i] = new char[5];
	}
	//Row1
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 1)	a[1][i] = '(';
		if (i == 2)	a[1][i] = '_';
		if (i == 3)	a[1][i] = ')';
		if (i == 4)	a[1][i] = '\\';
	}
	//Row3
	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}
cPlayer::cPlayer(cPosition pos) : isDead(false), pos(pos) {
	//pos.setPos(pos.getX(), pos.getY());
	a = new char*[3];
	emptyPlayer = new char*[3];
	for (int i = 0; i < 3; ++i) {
		emptyPlayer[i] = new char[5];
		for (int j = 0; j < 5; ++j) {
			emptyPlayer[i][j] = ' ';
		}
	}
	for (int i = 0; i < 3; i++){
		a[i] = new char[5];
	}
	//Row1
	for (int i = 0; i < 5; i++) {
		if (i == 2)
			a[0][i] = 'O';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 5; i++) {
		if (i == 0)	a[1][i] = '/';
		if (i == 1)	a[1][i] = '(';
		if (i == 2)	a[1][i] = '_';
		if (i == 3)	a[1][i] = ')';
		if (i == 4)	a[1][i] = '\\';
	}
	//Row3
	for (int i = 0; i < 5; i++) {
		if (i == 1)	a[2][i] = '/';
		else if (i == 3)	a[2][i] = '\\';
		else a[2][i] = ' ';
	}
}
cPlayer::~cPlayer(){
	for (int i = 0; i < 3; i++) {
		delete[] a[i];
		delete[] emptyPlayer[i];
	}
	delete[] a;
	delete[] emptyPlayer;
}
void cPlayer::killPlayer() {
	isDead = true;
}
char ** cPlayer::shape() {
	return a;
}
char ** cPlayer::emptyShape() {
	return emptyPlayer;
}
cPosition cPlayer::getPos() {
	return pos;
}
int cPlayer::getX() {
	return pos.getX();
}
int cPlayer::getY() {
	return pos.getY();
}
int cPlayer::getHeight() {
	return height;
}

int cPlayer::getWidth() {
	return width ;
}
void cPlayer::Up() {
	sound();
	if (pos.getX() <= 3) return;
	pos.setPos(pos.getX() - 3, pos.getY());
}
void cPlayer::Down() {
	sound();
	if (pos.getX() + 3 > 34) return;
	pos.setPos(pos.getX() + 3, pos.getY());
}
void cPlayer::Left() {
	sound();
	if (pos.getY() <= LEFTMAP) return;
	pos.setPos(pos.getX(), pos.getY() - 1);
}
void cPlayer::Right() {
	sound();
	if (pos.getY() + 2 >= RIGHTMAP) return;
	pos.setPos(pos.getX(), pos.getY() + 1);
}

bool cPlayer::checkIsDead() {
	return isDead;
}

bool cPlayer::crash(cPosition pos, int w, int h) {
	int magicConst = 3;
	if (w == 5) {
		//crash while Car/Truck on the right
		magicConst = 3;
		if (this->getX() == pos.getX()) {
			if (this->getY() <= pos.getY() && max(getY(), pos.getY()) <= min(getY() + getWidth() - magicConst, pos.getY() + w - magicConst))
			{
				return true;
			}
			if (this->getY() >= pos.getY() && getY() - pos.getY() <= 3)
				return true;
		}
	}
	if (w == 3) {
		magicConst = 1;
		if (this->getX() == pos.getX())
		{
			if (this->getY() >= pos.getY() && pos.getY() + w - magicConst >= this->getY()) // crash while bird on the left
			{
				return true;
			}
			if (getY() <= pos.getY() && pos.getY() - getY() <= 2) //crash while bird on the right
				return true;
		}
	}
	else
		if (this->getX() == pos.getX() && max(getY(), pos.getY()) <= min(getY() + getWidth() - magicConst, pos.getY() + w - magicConst)) {
			return true;
		}
	return false;
}


void cPlayer::sound(){
	if(!constantVar::isMute && !isDead)
	PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
}
