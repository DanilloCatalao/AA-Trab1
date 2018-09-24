#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "selection.h"
#include "mergesort.h"
#include "helper.h"

int LinearSelection( int* list, int n, int k ){
    const int group_length = 5;
    int group_count;
    int medianOfMedians;
    int i, j, w, remainder;
    int *list_copy;
    int *median_list, *above_median_list, *below_median_list;
    int *group;
    int result;

    list_copy = _malloc(n * sizeof(int));
    memcpy(list_copy, list, n * sizeof(int));

    // Caso base
    if(n <= group_length) {
	merge_sort(list_copy, n);
	k -= 1;
	result = list_copy[k];
	free(list_copy);

	return result;
    }

    group_count = n / group_length;
    if(n % group_length != 0) {
	group_count += 1;
    }

    median_list = (int *) _malloc(group_count * sizeof(int));

    //Group the numbers into sets of 5
    //Sort individual groups and find the median of each group; put these medians in a set M
    for(i = 0; i < group_count-1; i++) {
	group = &list_copy[i * group_length];
	merge_sort(group, group_length);
	median_list[i] = group[group_length/2];
    }
    remainder = n - (i * group_length);
    group = &list_copy[(group_count-1)*group_length];
    merge_sort(group, remainder);
    median_list[group_count-1] = group[remainder/2];

    free(list_copy);

    //Find median m’ of set M using LinearSelection(M,sizeof(M))
    medianOfMedians = LinearSelection(median_list, group_count, group_count / 2);

    free(median_list);

    above_median_list = (int *) _malloc(7 * n / 10 * sizeof(int));
    below_median_list = (int *) _malloc(7 * n / 10 * sizeof(int));

    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    j = 0;
    w = 0;
    for(i = 0; i < n; i++) {
	if(list[i] < medianOfMedians) {
	    below_median_list[j] = list[i];
	    j++;
	} else if(list[i] > medianOfMedians){
	    above_median_list[w] = list[i];
	    w++;
	}
    }

    if(j == k - 1) {
	result = medianOfMedians;
    } else if(j > k - 1) {
	result = LinearSelection(below_median_list, j, k);
    } else {
	result = LinearSelection(above_median_list, w, k - j - 1);
    }

    free(above_median_list);
    free(below_median_list);

    return result;
}

int sortSelection(int *list, int n, int k) {
    int result;
    int *list_copy = _malloc(n * sizeof(int));
    memcpy(list_copy, list, n * sizeof(int));

    merge_sort(list_copy, n);
    k -= 1;
    result = list_copy[k];

    free(list_copy);

    return result;
}

