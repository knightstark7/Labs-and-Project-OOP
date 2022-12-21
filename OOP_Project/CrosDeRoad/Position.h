#pragma once
class Position {
	int X, Y;
public:
	int getX();
	int getY();
	Position() {
		X = Y = 0;
	};
	Position(const int x, const int y) {
		X = x;
		Y = y;
	}
	void setPos(int x, int y) {
		this->X = x;
		this->Y = y;
	}
	~Position() {};
};

