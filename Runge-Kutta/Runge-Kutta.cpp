#include <stdlib.h>
#include <stdio.h>
#include "System.h"
#include <omp.h>

int main() {
	System *s = (System*)malloc(600000 * sizeof(System));
	double startTime = omp_get_wtime();
	for (int i = 0; i < 600000; i++) {
		s[i] = createSystem();
		seqCalculateSystem(s[i]);
	}
	double endTime = omp_get_wtime();
	printf("Seq TIME: %f sec\n", endTime - startTime);
	startTime = omp_get_wtime();
	#pragma omp parallel for
	for (int i = 0; i < 600000; i++) {
		s[i] = createSystem();
		parCalculateSystem(s[i]);
	}
	endTime = omp_get_wtime();
	printf("Paral TIME: %f sec\n", endTime - startTime);
	system("pause");
	return 1;
}
