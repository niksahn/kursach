#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Square.h"

class ComplexFigure : public Figure {
private:
	Square s;
	Circle c;
public:
	ComplexFigure(Square _s, Circle _c);
	void draw() override;
	void move(int new_x, int new_y) override;
	void hide() override;
};
