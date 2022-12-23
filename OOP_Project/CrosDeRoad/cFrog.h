#pragma once
#include "head.h"
#include "Enemy.h"

class cFrog : public Enemy{
	char **a;
public:
	cFrog(Position pos);
	char ** shape();
	void sound();
	int getlength(){
		return 9;
	}
	int getType();
	cFrog();
	~cFrog();
};

