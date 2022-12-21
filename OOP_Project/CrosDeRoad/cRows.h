#pragma once
#include "head.h"
#include "cLine.h"

class cRows{
private:
	vector <cLine*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, Enemy* enemy); //  push a new enemy to a row
	void pushRow(cLine*);
	vector <Enemy*> listEnemy(); // return all enemies from all rowsgit ad
	vector <cLine*> listRow();
	int nextState(int t);
	void redrawState();

};

