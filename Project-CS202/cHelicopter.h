#pragma once
#include "head.h"
#include "Enemy.h"

class cHelicopter : public Enemy{
	char** a; //a[3][11]
public:
	cHelicopter(cPosition pos);
	char **shape();
	void sound();
	int getlength(){
		return 11;
	}
	int getType();
	cHelicopter();
	~cHelicopter();
};

