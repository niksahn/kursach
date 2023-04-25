#pragma once
#include <windows.h>
#include <windowsx.h>
#include <string>

using namespace std;
class Circle;
class Square;
class Figure {
protected:
	int x, y;
	HWND hwnd; //идентификатор окна
	HDC hdc; // контекст изображения
	RECT rt; // координаты прямоугольного окна
	COLORREF color; // color
public:
	Figure(int _x = 0, int _y = 0, COLORREF c = RGB(0, 0, 0));
	class FigureExeption {
	public:
		string name;
		FigureExeption(string n) : name(n) {};
	};
	virtual void draw() = 0;
	void move(int new_x, int new_y);
	virtual void hide() {};
	~Figure();
	
};
