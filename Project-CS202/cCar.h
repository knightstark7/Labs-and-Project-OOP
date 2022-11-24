#pragma once
#include "head.h"
#include "Enemy.h"

class cCar : public Enemy{
	char **a; //a[3][8]
public:
	cCar(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getlength(){
		return 8;
	}
	int getType();
	cCar();
	~cCar();

};
