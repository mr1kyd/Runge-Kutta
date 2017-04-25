#pragma once

typedef struct Equation
{
	double n;// ���������� �����
	double t;// ������� ���
	double dt;// ��� �� �������
	double x0;
	double xx0;
	double *result;
};

Equation createEquation(double dt, double t0, double tn);

void calculateEquation(Equation e, double r);