#include "cFrog.h"

cFrog::cFrog(cPosition pos) : Enemy(pos) {
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
void cFrog::test() {
	//Row1
	a[0][0] = ' ';
	a[0][1] = ' ';
	a[0][2] = ' ';
	a[0][3] = ' ';
	a[0][4] = (char)219;
	a[0][5] = (char)223;
	//Row2
	a[1][0] = (char)223;
	a[1][1] = (char)254;
	a[1][2] = (char)219;
	a[1][3] = (char)219;
	a[1][4] = (char)219;
	a[1][5] = (char)221;
	//Row3
	a[2][0] = ' ';
	a[2][1] = '|';
	a[2][2] = '|';
	a[2][3] = ' ';
	a[2][4] = '|';
	a[2][5] = '|';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
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