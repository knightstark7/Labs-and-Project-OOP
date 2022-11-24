#include "cCar.h"

cCar::cCar(cPosition pos) : Enemy(pos) {
	a = new char*[3];
	for (int i = 0; i < 3; i++){
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ';
		else
			a[0][i] = '_';
	}
	//Row2
	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i>0 && i<5)	a[1][i] = ' ';
		if (i == 5)	a[1][5] = char(220);
		if (i == 6)	a[1][6] = '\\';
		else a[1][i] = ' ';
	}
	//Row3
	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)240;
		else
			if (i == 1 || i == 5)a[2][i] = 'O';
			else
				//cout << (char)196;
				a[2][i] = '-';
	}
	a[2][7] = (char)217;
};


cCar::cCar()
{
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ';
		else
			a[0][i] = '_';
	}
	//Row2
	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i>0 && i<5)	a[1][i] = ' ';
		if (i == 5)	a[1][5] = char(220);
		if (i == 6)	a[1][6] = '\\';
		else a[1][i] = ' ';
	}
	//Row3
	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)240;
		else
			if (i == 1 || i == 5)a[2][i] = 'O';
			else
				//cout << (char)196;
				a[2][i] = '-';
	}
	a[2][7] = (char)217;
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
void cCar::test()
{
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 6 || i == 7 || i == 8)
			a[0][i] = ' ';
		else
			a[0][i] = '_';
	}
	//Row2
	a[1][0] = '/';
	for (int i = 1; i < 8; i++) {
		if (i>0 && i<5)	a[1][i] = ' ';
		if (i == 5)	a[1][5] = char(220);
		if (i == 6)	a[1][6] = '\\';
		else a[1][i] = ' ';
	}
	//Row3
	for (int i = 0; i < 7; i++) {
		if (i == 0)a[2][i] = (char)240;
		else
			if (i == 1 || i == 5)a[2][i] = 'O';
			else
				//cout << (char)196;
				a[2][i] = '-';
	}
	a[2][7] = (char)217;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

}
int cCar::getType()
{
	return 1;
}