#include "bubble_sort.h"

int bubble_sort(int *array, int size) {
    if (!array) {
        puts("Empty array has been passed\nNothing to sort");
        return -1;
    }
    if (size <= 0) {
        puts("Size passed is invalid");
        return -2;
    }
    int i = 0, j = 0;
    for (; i < size - 2; i++) {
        for (j = 0; j < size-1-i; j++) {
            if (array[j+1] < array[j]) {
                swap(array, j, j+1);
            }
        }
    }
    return 0;
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
