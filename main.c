#include <stdio.h>
#include "linearSelection.h"
#include "mergesort.h"



static void debug_show(int *list, int n) {
    int i;
    for(i = 0; i < n; i ++) {
	printf("%d ", list[i]);
    }
    printf("\n");
}



int main(void){
    int list[] = {2,5,9,19,24,54,5,87,9,10,44,32,18,13,2,
				4,23,26,16,17,25,39,47, 56,71};
    printf("%d\n",LinearSelection(list, sizeof(list)/sizeof(int), 5));

    /* merge_sort(list, sizeof(list)/sizeof(int)); */
    /* debug_show(list, sizeof(list)/sizeof(int)); */
    return 0;
}
