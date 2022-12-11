#pragma once
#include "head.h"
#include "Enemy.h"

class cWorm : public Enemy{
	char **a; //a[3][3]
public:
	cWorm(cPosition pos);
	char **shape();
	void sound();
	int getlength(){
		return 5;
	}
	int getType();
	cWorm();
	~cWorm();
};

