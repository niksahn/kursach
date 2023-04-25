#include "Figure.h"

Figure::Figure(int _x , int _y , COLORREF c ) : x(_x), y(_y), color(c) {
	hwnd = 0;

	if ((hwnd = GetConsoleWindow()) == 0)
	{
		throw FigureExeption("Window not found!!!");
	}

	if ((hdc = GetDC(hwnd)) == 0)
	{
		throw FigureExeption("Error with window context!");
	}

	GetClientRect(hwnd, &rt);
}


void Figure:: move(int new_x, int new_y) {
	hide();
	x = new_x;
	y = new_y;
	draw();
}

Figure::~Figure()
{
	ReleaseDC(hwnd, hdc);
}