#include "Equation.h"
#include <stdlib.h>
#include <math.h>

double f1(double x) {
	return x;
}

double f2(double x, double r){
	return -(x / (r*r));
}

double random(double range) {
	int range_min = -range, range_max = range, rang_double = 4;
	srand(80808);
	return range_min + 1 + rand() % (range_max - range_min + 1) - (rand() % ((int)pow(10, rang_double)) / pow(10, rang_double));
}

Equation createEquation(double dt, double t0, double tn) {
	Equation result;
	result.n = (tn - t0) / dt;
	result.t = t0;
	result.dt = dt;
	result.x0 = random(2);
	result.xx0 = random(0.0005);
	return result;
}

void calculateEquation(Equation e, double r) {
	double *m = (double*)malloc(e.n * sizeof(double));
	double *x = (double*)malloc(e.n * sizeof(double));
	m[0] = e.x0;
	x[0] = e.xx0;
	for (int i = 0; i < e.n - 1; i++) {
		double m1 = (f2(m[i], r));
		double m2 = (f2((m[i] + (e.dt * m1) / 2), r));
		double m3 = (f2((m[i] + (e.dt * m2) / 2), r));
		double m4 = (f2((m[i] + e.dt * m3), r));
		m[i + 1] = m[i] + e.dt * (m1 + 2 * m2 + 2 * m3 + m4) / 6.0;
		double x1 = e.dt * f1(m[i]);
		double x2 = e.dt * f1(m[i] + (e.dt * x1) / 2);
		double x3 = e.dt * f1(m[i] + (e.dt * x2) / 2);
		double x4 = e.dt * f1(m[i] + e.dt * x3);
		x[i + 1] = x[i] + e.dt * (x1 + 2 * x2 + 2 * x3 + x4) / 6.0;
	}
	e.result = x;
}