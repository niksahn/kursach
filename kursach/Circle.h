#pragma once
#include "Figure.h"

class Square;
class Circle : public Figure {
private:
	int radius;
public:
	Circle(int _x = 0, int _y = 0, int r = 0, COLORREF c = RGB(0, 0, 0)) : Figure(_x, _y, c), radius(r) { }
	void draw() override {
		if (((x - radius) <= rt.left) ||
			((x + radius) >= rt.right) ||
			((y - radius) <= rt.top) ||
			((y + radius) >= rt.bottom)
			) throw FigureExeption("Out of border!!!");
		cout << " Circle draw: "; cout << radius << endl;
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
	void hide() override {
		//  выводим информацию об окружности
		cout << " Circle hide: "; cout << radius << endl;
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
	friend bool checkAgrigate(Square, Circle);
};
