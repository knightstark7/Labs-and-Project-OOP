#pragma once
#include "head.h"
#include "Enemy.h"

class cCar : public Enemy{
	char **a;
public:
	cCar(Position pos);
	char ** shape();
	void sound();
	int getlength(){
		return 11;
	}
	int getType();
	cCar();
	~cCar();

};
