#include "Figures.h"


void Figures::add(Figure* f) { Figures::figures_vector.push_back(f); }
void Figures::show() {
	for (auto figure : figures_vector)
	{
		figure->draw();
	}
}

Figures::~Figures() {
	for (auto figure : figures_vector)
	{
		figures_vector.pop_back();
		
	}
}