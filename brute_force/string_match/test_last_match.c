#include "../../minunit.h"
#include "./first_match/string_match.h"
#include <stdio.h>

int tests_run = 0;

/**
 * Plan:
 * 1. Test behaviour when text is null and/or pattern is null
 * 2. Test behaviour when length of pattern is less than length of text
 * 3. Test behaviour under normal conditions
 */

static char* test_null() {
    char *text1 = NULL;
    char *pattern1 = "Hello";
    mu_assert("error, searched NULL array", string_match(text1, pattern1) == -2);

    char *text2 = "hello";
    char *pattern2 = NULL;
    mu_assert("error, searched NULL array", string_match(text1, pattern1) == -2);

    char *text3 = NULL;
    char *pattern3 = NULL;
    mu_assert("error, searched NULL array", string_match(text1, pattern1) == -2);
    return 0;
}

static char* test_text_lt_pattern() {
    char *text = "hi";
    char *pattern = "Hello";
    mu_assert("error, did not return failure", string_match(text, pattern) == -3);
    return 0;
}

static char* test_successful_match() {
    char *text = "hello";
    char *pattern1 = "he";
    mu_assert("error, did not find the pattern", string_match(text, pattern1) == 1);

    char *pattern2 = "lo";
    mu_assert("error, did not find the pattern", string_match(text, pattern2) == 4);

    char *pattern3 = "hello";
    mu_assert("error, did not find the pattern", string_match(text, pattern3) == 1);

    char *text1 = "hehehe";
    char *pattern4 = "he";
    mu_assert("error, did not find the pattern", string_match(text1, pattern4) == 5);
    return 0;
}

static char* test_unsuccessful_match() {
    char *text = "hello";
    char *pattern = "nlo";
    mu_assert("error, found an non-existant substring", string_match(text, pattern) == -1);
    return 0;
}

static char* test_len_zero() {
    char *text1 = "hello";
    char *pattern1 = "";
    mu_assert("error, found an empty character", string_match(text1, pattern1) == -4);

    char *text2 = "";
    char *pattern2 = "";
    mu_assert("error, found an empty character", string_match(text2, pattern2) == -4);
    return 0;
}

static char* all_tests() {
    mu_run_test(test_null);
    mu_run_test(test_successful_match);
    mu_run_test(test_unsuccessful_match);
    mu_run_test(test_len_zero);
    mu_run_test(test_text_lt_pattern);
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
