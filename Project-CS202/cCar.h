#pragma once
#include "head.h"
#include "Enemy.h"

class cCar : public Enemy{
	char **a; //a[3][15]
public:
	cCar(cPosition pos);
	char ** shape();
	void sound();
	int getlength(){
		return 11;
	}
	int getType();
	cCar();
	~cCar();

};
