#include "Square.h"
#include "Figure.h"

Square::Square(int _x , int _y , int d , COLORREF c) : Figure(_x, _y, c), side(d) {/* Figures::add(this);*/ }
void Square::draw()  { //cout « "Square: " « x « ", " « y«", "« diagonal;
	if (
		((x + side / 2) >= rt.right) ||
		((y - side / 2) <= rt.top) ||
		((y + side / 2) >= rt.bottom)
		) throw FigureExeption("Out of border!!!");
	//cout << " Square draw: "; cout << side << endl;
	// рисуем квадрат
	HPEN   pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, x + side / 2, y + side / 2, x - side / 2, y - side / 2);
	// освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
}