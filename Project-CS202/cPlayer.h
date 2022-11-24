#pragma once
#include "headerFile.h"

class cPlayer{

private:
	cPosition pos;
	bool isDead;
	char **a;  //a[3][5]
	char ** emptyPlayer;
	int width = 5, height = 3;
public:
	cPlayer(); // set default position
	cPosition getPos();
	cPlayer(cPosition pos); // set current position when load game
	~cPlayer();
	void Up();
	void Down();
	void Right();
	void Left();
	bool checkIsDead();
	void killPlayer(); // set isDead
	char **shape();
	char **emptyShape();
	//cPosition getPos();
	int getWidth();
	int getHeight();
	//    bool crash(cEnemy);
	int getX();
	int getY();
	bool crash(cPosition pos, int w, int h);
	void sound();
};
#endif // cPlayer