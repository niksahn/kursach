#include "Circle.h"

Circle::Circle(int _x, int _y, int r, COLORREF c) : Figure(_x, _y, c), radius(r) {
	checkBorder();
}

void Circle::checkBorder() {
	if (((x - radius) <= rt.left) ||
		((x + radius) >= rt.right) ||
		((y - radius) <= rt.top) ||
		((y + radius) >= rt.bottom)
		) throw FigureExeption("Out of border!!!");
};

void Circle::draw() {
	checkBorder();
	cout << " Circle draw: "; cout << "x: " << x << " y: " << y << " radius :" << radius << endl;
	// ������ ����������
	HPEN   pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	// ����������� �������
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::hide() {
	//  ������� ���������� �� ����������
	cout << " Circle hide: "; cout << "x: " << x << " y: " << y << " radius :" << radius << endl;
	// ������ ���������� ������ ����
	HPEN   pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	// ����������� �������
	DeleteObject(pen);
	DeleteObject(brush);
}