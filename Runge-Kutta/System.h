#pragma once
#include "Equation.h"

typedef struct System
{
	Equation x;
	Equation y;
	Equation z;
};

System createSystem();

System createSystem(Equation x, Equation y, Equation z);
