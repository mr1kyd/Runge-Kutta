#pragma once
#include "Equation.h"

typedef struct System
{
	Equation x;
	Equation y;
	Equation z;
	double r;
};

System createSystem();

void seqCalculateSystem(System s);
void parCalculateSystem(System s);
