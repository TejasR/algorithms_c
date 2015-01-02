#include <stdio.h>
#include "../minunit.h"
#include "./using_array/selection_sort.h"

int tests_run = 0;

/**
 * Normal operation is tested
 */
static char* test_normal_ops() {
    int array[] = {10, 34, 23, 9, -5, -7, 0};
    
    mu_assert("error, did not return 0", selection_sort(array, 0) == -2);
    mu_assert("error, did not return 0", selection_sort(array, 7) == 0);
    int i;
    for (i=0; i<7; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}

/**
 * Test behaviour if NULL is passed in place of an array
 */
static char* test_null() {
    int *array = NULL;
    
    mu_assert("error, did not return -1", selection_sort(array, 0) == -1);
    mu_assert("error, did not return -1", selection_sort(array, 3) == -1);
    mu_assert("error, did not return -1", selection_sort(array, -2) == -1);
    return 0;
}

/**
 * Testing behaviour when size of the array passed is less than length of the array
 * The length of array specified will be sorted and not the remaining elements
 */
static char* test_lt_size() {
    int array[] = {128, 100, 10, -23, 0, -126};
    
    mu_assert("error, did not return -1", selection_sort(array, 3) == 0);
    int i;
    printf("Sorted: ");
    for (i=0; i<3; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
    printf("Complete array: ");
    for (i=0; i<6; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}

static char* all_tests() {
    mu_run_test(test_normal_ops);
    mu_run_test(test_null);
    mu_run_test(test_lt_size);
    return 0;
}

int main()
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}