#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

static int *merge(int *list1, int n1, int *list2, int n2);
static void debug_show(int *list, int n);

void merge_sort(int *list, int n) {
    int i;
    int *merge_result;
    if(n == 1) {
	return;
    }

    merge_sort(list, n/2);
    merge_sort(&list[n/2], n - n/2);
    merge_result = merge(list, n/2, &list[n/2], n - n/2);
    for(i = 0; i < n; i++) {
	list[i] = merge_result[i];
    }
    free(merge_result);
}

static int *merge(int *list1, int n1, int *list2, int n2) {
    int i, j, k;
    int *remainder;
    int remainder_size;
    int *result = (int *) malloc((n1 + n2) * sizeof(int));
    if(result == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2) {
	if(list1[i] < list2[j]) {
	    result[k] = list1[i];
	    i++;
	} else {
	    result[k] = list2[j];
	    j++;
	}

	k++;
    }

    if(i < n1) {
	remainder = &list1[i];
	remainder_size = n1 - i;
    } else if(j < n2) {
	remainder = &list2[j];
	remainder_size = n2 - j;
    }

    i = 0;
    while(i < remainder_size) {
	result[k] = remainder[i];
	k++;
	i++;
    }

    return result;
}

static void debug_show(int *list, int n) {
    int i;
    for(i = 0; i < n; i ++) {
	printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[] = {5, 3, 0, 7, 1, 2, 9, 4, 6, 8};
    merge_sort(list, 10);
    debug_show(list, 10);
    return 0;
}

