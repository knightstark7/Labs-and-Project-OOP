#pragma once
#include "head.h"
#include "Enemy.h"

class cTruck : public Enemy{
	char** a; //a[3][8]
public:
	cTruck(cPosition pos);
	char **shape();
	void sound();
	void test();
	int getlength(){
		return 8;
	}
	int getType();
	cTruck();
	~cTruck();
};

