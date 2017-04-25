#pragma once

typedef struct Equation
{
	double n;// Количество шагов
	double t;// текцщий шаг
	double dt;// шаг по времени
	double x0;
	double xx0;
	double *result;
};

Equation createEquation(double dt, double t0, double tn);

void calculateEquation(Equation e, double r);