#pragma once

typedef struct Equation
{
	double n;// ���������� �����
	double t;// ������� ���
	double dt;// ��� �� �������
};

Equation createEquation(double dt, double t0, double tn);

void calculate(Equation e);