#pragma once
#include "head.h"
#include "Console.h"
#include "cPosition.h"

class Enemy{
private:
	cPosition point;
	bool outMap;
public:
	cPosition getPos();
	int getX();
	int getY();
	Enemy();
	Enemy(cPosition st); // create new enemy with starting position
	virtual ~Enemy() = default;
	virtual char **shape() = 0; // return the shape of enemy to draw
	virtual void sound() = 0;
	virtual int getType() = 0;
	void updatePosition(int dx, int dy);
	bool isOutOfMap();
	void goOutMap();
	virtual int getlength();
	int getwidth();
};