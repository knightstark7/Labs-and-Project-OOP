#pragma once
#include "head.h"
#include "Enemy.h"

class cHelicopter : public Enemy{
	char** a;
public:
	cHelicopter(Position pos);
	char **shape();
	void sound();
	int getlength(){
		return 11;
	}
	int getType();
	cHelicopter();
	~cHelicopter();
};


