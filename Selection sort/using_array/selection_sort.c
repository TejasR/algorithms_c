#include "selection_sort.h"

/*
 * Limits:
 * 1. If the size of the array passed is less than the
 * actual size of the array then only those elements of the 
 * array will be sorted
 * 2. If the size of the array passed is greater than the
 * actual size of the array, then it might result in a 
 * segmentation fault and the sort might fail.
 */
int selection_sort( int *array, int n ) {
    if (!array) {
        puts("Null value passed for array");
        return -1;
    }
    if (n <= 0) {
        puts("Size of the array is bad value");
        return -2;
    }
    int minimum;
    int i, j;
    for( i=0; i<=n-2; i++ ){
        minimum = i;
        for( j=i+1; j<=n-1; j++ ) {
            if ( array[minimum] > array[j] ) minimum = j;
        }
        swap(array, i, minimum);
    }
    return 0;
}

void swap(int *array, const int i, const int j) {
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return;
}