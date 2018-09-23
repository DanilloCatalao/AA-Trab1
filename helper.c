#include <stdio.h>
#include <stdlib.h>


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

