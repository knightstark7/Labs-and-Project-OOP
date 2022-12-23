#pragma once
#include "head.h"
#include "cLine.h"

class cRows{
private:
	vector <cLine*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, Enemy* enemy);
	void pushRow(cLine*);
	vector <Enemy*> listEnemy();
	vector <cLine*> listRow();
	int nextState(int t);
	void redrawState();

};

