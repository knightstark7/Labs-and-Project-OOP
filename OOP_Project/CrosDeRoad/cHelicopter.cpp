#include "cHelicopter.h"

cHelicopter::cHelicopter(Position pos) : Enemy(pos) {

	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[11];
	}
	char b[3][15] = { "    ---|---",
					  "*>====[_]L)",
					  "      -'-`-" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 11; j++) {
			a[i][j] = b[i][j];
		}
	}

};


char **cHelicopter::shape()
{
	return a;
};
void cHelicopter::sound()
{
	PlaySound(TEXT("Helicopter.wav"), NULL, SND_ASYNC);
}
cHelicopter::cHelicopter()
{
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[11];
	}
	char b[3][15] = { "    ---|---",
					  "*>====[_]L)",
					  "      -'-`-" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 11; j++) {
			a[i][j] = b[i][j];
		}
	}

}
cHelicopter::~cHelicopter()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

int cHelicopter::getType()
{
	return 4;
}