#include "../minunit.h"
#include "./using_array/bubble_sort.h"
#include <stdio.h>

int tests_run = 0;

/**
 * Plan:
 * 1. Test behaaviour when array is null
 * 2. Test behaviour under normal conditions
 * 3. Test behaviour when size of array specified is less than size of the array
 */

static char* test_null() {
    int *array = NULL;

    mu_assert("error, sorted NULL array", bubble_sort(array, 10) == -1);
    mu_assert("error, sorted NULL array", bubble_sort(array, -4) == -1);
    mu_assert("error, sorted NULL array", bubble_sort(array, 0) == -1);
    return 0;
}

static char* test_invalid_size() {
    int array[] = {1, 6, 4};

    mu_assert("error, sorted array with 0 elements", bubble_sort(array, 0) == -2);
    mu_assert("error, sorted array with negative size", bubble_sort(array, -5) == -2);
    return 0;
}

static char* test_normal_op() {
    int array[] = {56, 43, 145, -67, -90, 0};

    mu_assert("error, sort was not successful", bubble_sort(array, 6) == 0);
    int i=0;
    for (;i<6;i++) {
        printf("%d\t",array[i]);
    }
    puts("");
    return 0;
}

static char* test_lt_size() {
    int array[] = {123, 10, -56, 0, 90, 154};

    mu_assert("error, unable to sort successful", bubble_sort(array, 3) == 0);
    int i=0;
    printf("Sorted: ");
    for (;i<3;i++) {
        printf("%d\t",array[i]);
    }
    puts("");
    printf("Complete array: ");
    for (i=0;i<6;i++) {
        printf("%d\t",array[i]);
    }
    puts("");
    return 0;
}

static char* all_tests() {
    mu_run_test(test_null);
    mu_run_test(test_invalid_size);
    mu_run_test(test_normal_op);
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
