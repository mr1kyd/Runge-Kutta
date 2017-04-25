#include "System.h"
#include "Equation.h"
#include <math.h>

System createSystem() {
	System result;
	result.x = createEquation(0.01, 0, 1);
	result.y = createEquation(0.01, 0, 1);
	result.z = createEquation(0.01, 0, 1);
	result.r = sqrt(pow(result.x.x0, 2) + pow(result.y.x0, 2) + pow(result.z.x0, 2));
	return result;
}

void seqCalculateSystem(System s) {
	calculateEquation(s.x, s.r);
	calculateEquation(s.y, s.r);
	calculateEquation(s.z, s.r);
}

void parCalculateSystem(System s) {
	#pragma omp parallel
	{
		#pragma omp section
		{
			calculateEquation(s.x, s.r);
		}
		#pragma omp section
		{
			calculateEquation(s.y, s.r);
		}
		#pragma omp section
		{
			calculateEquation(s.z, s.r);
		}
	}
}