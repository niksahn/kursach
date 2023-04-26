#pragma once
#include <windows.h>
#include <windowsx.h>
#include <string>
#include <iostream>

using namespace std;

class Figure {
protected:
	int x, y;
	HWND hwnd; //идентификатор окна
	RECT rt; // координаты прямоугольного окна
	COLORREF color; // color
public:
	HDC hdc; // контекст изображения
	Figure(int _x = 0, int _y = 0, COLORREF c = RGB(0, 0, 0));
	class FigureExeption {
	public:
		string name;
		FigureExeption(string n) : name(n) {};
	};
	virtual void checkBorder(){};
	virtual void draw() = 0;
	virtual void move(int new_x, int new_y);
	virtual void hide() = 0;
	~Figure();	
};