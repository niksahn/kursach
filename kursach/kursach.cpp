#include <iostream>
#include "Figure.h"
#include "Figures.h"
#include "Circle.h"
#include "Square.h"
#include "ComplexFigure.h"

using namespace std;

const int NotUsed = system("color F0");


bool checkAgrigate(Square a, Circle b) {
	return ((a.x == b.x) && (a.y == b.y) && (a.side / 2 == b.radius));
}

int main()
{
	SetConsoleTitle((LPCWSTR)L"22VP3"); //заголовок окна
	Sleep(1200);
	//устанавливаем позицию курсора в окне и выводим текст
	COORD p = { 1, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	try {
		Figures vectFig;
		Square s(150, 150, 160, RGB(255, 0, 250));
		Circle c(150, 150,80,RGB(0, 255, 0));
		vectFig.add(&s);
		vectFig.add(&c);
	  //  ComplexFigure af(s, c);	  
		vectFig.show();	
	}
	catch (Figure::FigureExeption figex) {
		cout<<figex.name;
	}
	Sleep(3600);
	p = { 1, 15 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}