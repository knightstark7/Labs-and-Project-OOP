#pragma once
#include "head.h"
#include "Enemy.h"

class cBird : public Enemy{
	char **a; //a[3][6]
public:
	cBird(cPosition pos);
	char **shape();
	void sound();
	void test();
	int getlength(){
		return 6;
	}
	int getType();
	cBird();
	~cBird();
};

