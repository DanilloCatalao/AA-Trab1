#include <stdio.h>
#include "selection.h"
#include "mergesort.h"
#include "helper.h"
#include "test.h"
#include <time.h>

int main(void){
	/*
    int list[] = {2,5,9,19,24,54,5,87,9,10,44,32,18,13,2,
				4,23,26,16,17,25,39,47, 56,71};
    //debug_show(list, 25);
    int result = LinearSelection(list, sizeof(list)/sizeof(int), 2);
    printf("\n");
    printf("result %d\n", result);
    //debug_show(list, 25);

    merge_sort(list, sizeof(list)/sizeof(int));
    //debug_show(list, 25);
	*/

	fullTest(10, 1000, 10);

    /*printf("\n");*/
    /*int a = sortSelection(list, sizeof(list)/sizeof(int), 2);*/
    /*printf("a: %d\n", a);*/
    /*debug_show(list, sizeof(list)/sizeof(int)); */
    return 0;
}
