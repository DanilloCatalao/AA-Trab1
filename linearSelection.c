#include <stdlib.h>
#include <stdio.h>
#include "linearSelection.h"
#include "mergesort.h"

int LinearSelection( int* list, int n, int k ){
    //Group the numbers into sets of 5
    //Sort individual groups and find the median of each group; put these medians in a set M
    //Find median m’ of set M using LinearSelection(M,sizeof(M))
    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    //If sizeof(L) = k-1 return m'
    //If sizeof(L) > k-1 retun LinearSelection()
    int group_count;
    int i;
    int **groups;

    group_count = n / 5;
    if(n % 5 != 0) {
	group_count += 1;
    }

    groups = (int **) malloc(group_count * sizeof(int*));
    if(groups == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    for(i = 0; i < group_count; i++) {
	groups[i] = &list[i * 5];
	merge_sort(groups[i], 5);
    }

    free(groups);
    return 0;
}

