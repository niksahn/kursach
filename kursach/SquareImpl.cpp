#pragma once
#include "Square.h"

Square::Square(int _x, int _y, int d, COLORREF c) : Figure(_x, _y, c), side(d) {
	checkBorder();
}
void Square::checkBorder() {
	if (((x - side / 2) <= rt.left) ||
		((x + side / 2) >= rt.right) ||
		((y - side / 2) <= rt.top) ||
		((y + side / 2) >= rt.bottom)
		) throw FigureExeption("Out of border!!!");
}
void Square::draw() {
	checkBorder();
//	cout << " Square draw: "; cout << "x: " << x << " y: " << y << " side :" << side << endl;
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

void Square::hide() {
	//  выводим информацию об окружности
//	cout << " Square hide: "; cout <<"x: " << x<<" y: " << y<<" side :" << side << endl;
	// рисуем окружность цветом фона
	HPEN   pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, x + side / 2, y + side / 2, x - side / 2, y - side / 2);
	// освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
}