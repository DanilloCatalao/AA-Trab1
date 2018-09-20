#include <stdlib.h>
#include <stdio.h>
#include "selection.h"
#include "mergesort.h"
#include "helper.h"

int LinearSelection( int* list, int n, int k ){
    //Group the numbers into sets of 5
    const int group_length = 5;
    int group_count;
    int medianOfMedians;
    int i, remainder;
    int *median_list, *above_median_list, *below_median_list;
    int **groups;

    // Caso base
    if(n <= group_length) {
	merge_sort(list, n);

	return list[k];
    }

    group_count = n / group_length;
    if(n % group_length != 0) {
	group_count += 1;
    }

    groups = (int **) _malloc(group_count * sizeof(int*));
    median_list = (int *) _malloc(group_count * sizeof(int));

    //Sort individual groups and find the median of each group; put these medians in a set M
    for(i = 0; i < group_count-1; i++) {
	groups[i] = &list[i * group_length];
	merge_sort(groups[i], group_length);
	median_list[i] = groups[i][group_length/2];
    }
    remainder = n - (i * group_length);
    groups[group_count-1] = &list[(group_count-1)*group_length];
    merge_sort(groups[group_count-1], remainder);
    median_list[group_count-1] = groups[group_count-1][remainder/2];

    //Find median m’ of set M using LinearSelection(M,sizeof(M))
    medianOfMedians = LinearSelection(median_list, group_count, group_count / 2);

    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    //If sizeof(L) = k-1 return m'
    //If sizeof(L) > k-1 retun LinearSelection()
    
    free(median_list);
    free(groups);

    return 0;
}

int sortSelection(int *list, int n, int k) {
    k -= 1;
    merge_sort(list, n);

    return list[k];
}

