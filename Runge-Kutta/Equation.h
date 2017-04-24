#pragma once

typedef struct Equation
{
	double n;// Количество шагов
	double t;// текцщий шаг
	double dt;// шаг по времени
};

Equation createEquation(double dt, double t0, double tn);

void calculate(Equation e);