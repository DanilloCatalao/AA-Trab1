#include <stdlib.h>
#include <stdio.h>
#include "selection.h"
#include "mergesort.h"

int LinearSelection( int* list, int n, int k ){
    //Group the numbers into sets of 5
    int group_count;
    int medianOfMedians;
    int i, remainder;
    int *median_list;
    int median;
    int **groups;

    // Caso base
    if(n == 5 && k == 2) {
	merge_sort(list, n);

	return list[2];
    }

    group_count = n / 5;
    if(n % 5 != 0) {
	group_count += 1;
    }

    median_list = (int *) malloc(group_count * sizeof(int));
    if(median_list == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    groups = (int **) malloc(group_count * sizeof(int*));
    if(groups == NULL) {
	printf("Dynamic memory allocation error.\n");
	exit(-1);
    }

    //Sort individual groups and find the median of each group; put these medians in a set M
    for(i = 0; i < group_count-1; i++) {
	groups[i] = &list[i * 5];
	merge_sort(groups[i], 5);
	median_list[i] = groups[i][2];
    }
    remainder = n - (i * 5);
    groups[group_count-1] = &list[(group_count-1)*5];
    merge_sort(groups[group_count-1], remainder);
    median_list[group_count-1] = groups[group_count-1][remainder/2];

    medianOfMedians = LinearSelection(median_list, 5, 2);

    //Find median m’ of set M using LinearSelection(M,sizeof(M))

    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    //If sizeof(L) = k-1 return m'
    //If sizeof(L) > k-1 retun LinearSelection()
    
    free(median_list);
    free(groups);

    return 0;
}

