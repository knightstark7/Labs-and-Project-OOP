#include "cTruck.h"

cTruck::cTruck(cPosition pos) : Enemy(pos) {

	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	a[0][0] = (char)218;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(196);
	a[0][7] = (char)191;
	//Row2
	a[1][0] = (char)179;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)
			a[1][i] = '[';
		else if (i == 7)
			a[1][i] = (char)179;
		else
			a[1][i] = ' ';
	}
	//Row3
	a[2][0] = (char)192;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)
			a[2][i] = 'O';
		else
			a[2][i] = (char)196;
	}
	a[2][7] = (char)217;

};


char **cTruck::shape()
{

	return a;
};
void cTruck::sound()
{
	PlaySound(TEXT("carstarthonkbackfire.wav"), NULL, SND_ASYNC);
}
cTruck::cTruck()
{
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	a[0][0] = (char)218;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(196);
	a[0][7] = (char)191;
	//Row2
	a[1][0] = (char)179;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '[';
		else if (i == 7)a[1][i] = (char)179;
		else
			a[1][i] = ' ';
	}
	//Row3
	a[2][0] = (char)192;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O';
		else
			a[2][i] = (char)196;
	}
	a[2][7] = (char)217;

}
cTruck::~cTruck()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

void cTruck::test()
{
	//Row1
	a[0][0] = (char)218;
	for (int i = 1; i < 7; i++)
		a[0][i] = char(196);
	a[0][7] = (char)191;
	//Row2
	a[1][0] = (char)179;
	for (int i = 1; i < 8; i++)
	{
		if (i == 6)a[1][i] = '[';
		else if (i == 7)a[1][i] = (char)179;
		else
			a[1][i] = ' ';
	}
	//Row3
	a[2][0] = (char)192;
	for (int i = 1; i < 7; i++) {
		if (i == 1 || i == 6)a[2][i] = 'O';
		else
			a[2][i] = (char)196;
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
int cTruck::getType()
{
	return 4;
}