#pragma once
#include "head.h"
#include "Enemy.h"

class cWorm : public Enemy{
	char **a;
public:
	cWorm(Position pos);
	char **shape();
	void sound();
	int getlength(){
		return 5;
	}
	int getType();
	cWorm();
	~cWorm();
};

