#include "sequential_search.h"

int sequential_search(int *array, int size, int keyword) {
    if (!array) {
        puts("NULL array was passed");
        return -2;
    }
    if (size <= 0) {
        puts("Size of the array is not mentioned correctly");
        return -3;
    }
    int i=0;
    for (;i<size;i++) {
        if (keyword == array[i]) {
            return i+1;
        }
    }
    return -1;
}
