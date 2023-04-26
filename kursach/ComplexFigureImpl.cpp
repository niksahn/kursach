#include "ComplexFigure.h"

ComplexFigure::ComplexFigure(Square _s, Circle _c):c(_c),s(_s) {
	if (!checkAgrigate(_s,_c)) throw FigureExeption("can`t make agrugate figure");
	c.hdc = hdc;
	s.hdc = hdc;
}

void ComplexFigure::draw()  {
	s.draw();
	c.draw();	
}

void  ComplexFigure::move(int new_x, int new_y) {
	s.move(new_x, new_y);
	c.move(new_x, new_y);
};

void  ComplexFigure::hide() {
	s.hide();
	c.hide();
}