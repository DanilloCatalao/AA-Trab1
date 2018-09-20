#include <stdlib.h>
#include <stdio.h>
#include "selection.h"
#include "mergesort.h"

int LinearSelection( int* list, int n, int k ){
    //Group the numbers into sets of 5
    int group_count;
    int medianOfMedians;
    int i;
    int *medians;
    int **groups;
    group_count = n / 5;

    if(n % 5 != 0) {
	group_count += 1;
    }

    medians = (int *) malloc(group_count * sizeof(int));
    if(medians == NULL) {
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
	medians[i] = list[(i*5)+2];
    }
    groups[group_count-1] = &list[(group_count-1)*5];
    merge_sort(groups[group_count-1], n%5==0 ? 5:n%5);
    medians[group_count-1] = groups[group_count-1][n%5==0? 2:(n%5)/2];


    //Find median m’ of set M using LinearSelection(M,sizeof(M))
    //medianOfMedians = LinearSelection(medians,group_count,group_count/2);

    //for(i=0;i<group_count;i++)printf(" %d ",medians[i]);

    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    //If sizeof(L) = k-1 return m'
    //If sizeof(L) > k-1 retun LinearSelection()
    
    free(medians);
    free(groups);

    return 0;
}

