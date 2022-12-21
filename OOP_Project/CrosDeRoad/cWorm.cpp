#include "cWorm.h"

cWorm::cWorm(Position pos) : Enemy(pos) {
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[5];
	}
	char b[3][6] = { " o.o ",
				     " >v< ",
				     " >O< " };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = b[i][j];
		}
	}
};

char ** cWorm::shape() {
	return a;
};
void cWorm::sound() {
	PlaySound(TEXT("Worm.wav"), NULL, SND_ASYNC);
};

cWorm::cWorm()
{
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[5];
	}
	char b[3][6] = { " o^o ",
				     " >v< ",
				     " >O< " };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = b[i][j];
		}
	}
}
cWorm::~cWorm()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
int cWorm::getType()
{
	return 0;
}