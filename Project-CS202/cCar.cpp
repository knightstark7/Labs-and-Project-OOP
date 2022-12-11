#include "cCar.h"

cCar::cCar(cPosition pos) : Enemy(pos) {
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[11];
	}
	char b[3][12] = { "   _______ ",
					  " _/_|[][] |",
					  "(-OO---OO-|" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 11; j++) {
			a[i][j] = b[i][j];
		}
	}
};


cCar::cCar()
{
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[11];
	}
	char b[3][12] = { "   _______ ",
					 " _/_|[][] |",
					 "(-OO---OO-|" };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 11; j++) {
			a[i][j] = b[i][j];
		}
	}
}
cCar::~cCar()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
char ** cCar::shape()
{
	return a;
}
void cCar::sound()
{
	PlaySound(TEXT("trafficjam.wav"), NULL, SND_ASYNC);
}

int cCar::getType()
{
	return 1;
}