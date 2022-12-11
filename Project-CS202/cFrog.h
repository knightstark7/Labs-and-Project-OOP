#pragma once
#include "head.h"
#include "Enemy.h"
class cFrog : public Enemy{
	char **a; //a[3][9]
public:
	cFrog(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getlength(){
		return 9;
	}
	int getType();
	cFrog();
	~cFrog();
};

