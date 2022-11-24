#pragma once
class cPosition {
	int X, Y;
public:
	int getX();
	int getY();
	cPosition() {
		X = Y = 0;
	};
	cPosition(const int x, const int y) {
		X = x;
		Y = y;
	}
	void setPos(int x, int y) {
		this->X = x;
		this->Y = y;
	}
	~cPosition() {};
};

