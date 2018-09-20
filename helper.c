#include <stdio.h>
#include <stdlib.h>

void *_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    return ptr;
}

