#include"linearSelection.h"

int LinearSelection( int* list, int k ){
    //Group the numbers into sets of 5
    //Sort individual groups and find the median of each group; put these medians in a set M
    //Find median m’ of set M using LinearSelection(M,sizeof(M))
    //Partition original data around m’ such that values less than it are in set L and values greater than it are in set R
    //If sizeof(L) = k-1 return m'
    //If sizeof(L) > k-1 retun LinearSelection()
    return 0;
}
