#include "../../minunit.h"
#include "./using_array/sequential_search.h"
#include <stdio.h>

int tests_run = 0;

/**
 * Plan:
 * 1. Test behaviour when array is null
 * 2. Test behaviour under normal conditions
 *  2.1. Succesful search
 * `2.2. Unsuccessful serach
 * 3. Test behaviour when size of array specified is less than size of the array and keyword is present but not in the size specified
 * 4. Test invalid size
 */

static char* test_null() {
    int *array = NULL;

    mu_assert("error, searched NULL array", sequential_search(array, 10, 10) == -2);
    mu_assert("error, searched NULL array", sequential_search(array, -1, 100) == -2);
    mu_assert("error, searched NULL array", sequential_search(array, 0, 10) == -2);
    return 0;
}

static char* test_invalid_size() {
    int array[] = {1, 6, 4};

    mu_assert("error, searched array with negative size", sequential_search(array, -20, 10) == -3);
    mu_assert("error, searched array with zero size", sequential_search(array, 0, 30) == -3);
    return 0;
}

static char* test_successful_search_op() {
    int array[] = {56, 43, 145, -67, -90, 0};

    mu_assert("error, search was not successful", sequential_search(array, 6, 0) == 6);
    mu_assert("error, search was not successful", sequential_search(array, 6, 43) == 2);
    mu_assert("error, search was not successful", sequential_search(array, 6, -67) == 4);
    return 0;
}

static char* test_unsuccessful_search_op() {
    int array[] = {56, 43, 145, -67, -90, 0};

    mu_assert("error, search was successful", sequential_search(array, 6, -66) == -1);
    mu_assert("error, search was successful", sequential_search(array, 6, 456) == -1);
    return 0;
}

static char* test_lt_size() {
    int array[] = {123, 10, -56, 0, 90, 154};

    mu_assert("error, found the keyword successfully", sequential_search(array, 3, 0) == -1);
    return 0;
}

static char* all_tests() {
    mu_run_test(test_null);
    mu_run_test(test_invalid_size);
    mu_run_test(test_successful_search_op);
    mu_run_test(test_unsuccessful_search_op);
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
