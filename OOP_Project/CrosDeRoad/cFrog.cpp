#include "cFrog.h"

cFrog::cFrog(Position pos) : Enemy(pos) {
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[9];
	}
	char b[3][10] = { "  ()-()  ",
					  ".-(___)-.",
					  " _<   >_ " };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = b[i][j];
		}
	}
};


char ** cFrog::shape() {

	return a;
};
void cFrog::sound() {
	PlaySound(TEXT("./Frog.wav"), NULL, SND_ASYNC);
};

cFrog::cFrog()
{
	a = new char* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new char[9];
	}
	char b[3][10] = { "  ()-()  ",
					  ".-(___)-.",
					  " _<   >_ " };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = b[i][j];
		}
	}
}
cFrog::~cFrog()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
int cFrog::getType()
{
	return 2;
}