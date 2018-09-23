#include "test.h"
#include "selection.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "helper.h"

void fullTest( int instance,int step, int iteration ) {
	const int MAX_INT = 100000;
	clock_t start, end;
	double cpu_time_used;
	int index;
	int i,j = 0;
	int **lists = NULL;
	lists = (int **)_malloc(instance * sizeof(int*));
	
	srand((unsigned int)time(NULL));
	for (i = step; i <= step * iteration; i += step) {
		index = (i / step) - 1;
		lists[index] = (int*)malloc(i * sizeof(int));
		fillList(lists[index], i, MAX_INT);
		start = clock();
		LinearSelection(lists[index], i, i / 2);
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("listSize: %d Time: %f\n", i, cpu_time_used);


		printf("ls : %d\n", LinearSelection(lists[0], 300, 1));
	}
}