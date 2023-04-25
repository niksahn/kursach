#pragma once
#include "Figure.h"


class Square : public Figure {
private:
	int side;
public:
	Square(int _x = 0, int _y = 0, int d = 0, COLORREF c = RGB(0, 0, 0)) : Figure(_x, _y, c), side(d) {/* Figures::add(this);*/ }
	void draw() override { //cout « "Square: " « x « ", " « y«", "« diagonal;
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
	friend bool checkAgrigate(Square, Circle);
};
