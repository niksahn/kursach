#pragma once
#include "Figure.h"


class ComplexFigure : public Figure {
private:
	Square s;
	Circle c;
public:
	ComplexFigure(Square _s, Circle _c) : s(_s), c(_c) {
		if (!checkAgrigate(_s, _c)) throw FigureExeption("can`t make agrugate figure");

	}
	void draw() override {
		c.draw();
		s.draw();
	}
};
