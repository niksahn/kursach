#pragma once
#include "Figure.h"
#include <vector>

class Figures {
public:
	 vector <Figure*> figures_vector;
	 void add(Figure* f);
	 void show();
	 ~Figures();
};