#pragma once
#include "head.h"
#include "Enemy.h"
class cDinosaur : public Enemy{
	char **a; //a[3][6]
public:
	cDinosaur(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getlength(){
		return 6;
	}
	int getType();
	cDinosaur();
	~cDinosaur();
};

