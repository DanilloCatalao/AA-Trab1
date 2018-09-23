#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void debug_show(int *list, int n) {
    int i;
    for(i = 0; i < n; i ++) {
	printf("%d ", list[i]);
    }
    printf("\n");
}

void *_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    return ptr;
}

void fillList(int * list, int size, int MAX) {
	int i;
	for (i = 0; i < size; i++) {
		list[i] = rand() % MAX + 1; 
	}
	return;
}
