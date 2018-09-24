#include "test.h"
#include "selection.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "helper.h"

void fullTest( int instance,int step, int iteration ) {
	const int MAX_INT = 100000;
	clock_t start, end;
	int index;
	double linearSelectTime = 0, sortSelectTime = 0;
	int i,j = 0;
	int *list = NULL;
	FILE *file = NULL;

	file = fopen("Resultado_testes.txt", "w");

	srand((unsigned int)time(NULL));
	for (i = step; i <= step * iteration; i += step) {
		fprintf(file, "N=%d\n", i);
		for (j = 0; j < 1; j++) {
			index = (i / step) - 1;
			list = (int*)malloc(i * sizeof(int));
			fillList(list, i, MAX_INT);
			start = clock();
			LinearSelection(list, i, i / 2);
			end = clock();
			linearSelectTime += ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			sortSelection(list, i, i / 2);
			end = clock();
			sortSelectTime += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		//linearSelectTime /= instance;
		//sortSelectTime /= instance;
		fprintf(file, "Média Linear Selection : %.8f\n", linearSelectTime);
		fprintf(file, "Média Sort Selection :   %.8f\n\n", sortSelectTime);
		linearSelectTime = 0;
		sortSelectTime = 0;
	}
	fclose(file);
}
