#pragma once
#include "Circle.h";
#include "Figure.h";

Circle::Circle(int _x, int _y, int r,  COLORREF c) : Figure(_x, _y, c), radius(r) {};

void Circle::draw()  {
	if (((x - radius) <= rt.left) ||
		((x + radius) >= rt.right) ||
		((y - radius) <= rt.top) ||
		((y + radius) >= rt.bottom)
		) throw FigureExeption("Out of border!!!");
	//cout << " Circle draw: "; cout << radius << endl;
	// рисуем окружность
	HPEN   pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	// освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::hide() {
	//  выводим информацию об окружности
	///cout << " Circle hide: "; cout << radius << endl;
	// рисуем окружность цветом фона
	HPEN   pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	// освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
}