#pragma once
#include "Figure.h"

class Circle : public Figure {
private:
	int radius;
public:
	Circle(int _x = 0, int _y = 0, int r = 0, COLORREF c = RGB(0, 0, 0));
	void draw() override;
	void hide() override;
	friend bool checkAgrigate(Square, Circle);
};
