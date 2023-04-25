#pragma once
#include "Figure.h"

class Circle;
class Square : public Figure {
private:
	int side;
public:
	Square(int _x = 0, int _y = 0, int d = 0, COLORREF c = RGB(0, 0, 0));
	void draw() override;
	friend bool checkAgrigate(Square, Circle);
};
