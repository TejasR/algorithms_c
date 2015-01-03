#include "string_match.h"

int string_match(char *text, char *pattern) {
    if (!text || !pattern) {
        puts("NULL has been passed as one of the parameters");
        return -2;
    }
    int len_of_text = strlen(text);
    int len_of_pattern = strlen(pattern);
    if (len_of_text < len_of_pattern) {
        puts("Length of text is less than length of the pattern that has to be matched");
        return -3;
    }
    if (len_of_text == 0 || len_of_pattern == 0) {
        puts("Length of text or pattern is equal to 0");
        return -4;
    }
    int i=0, j=0;
    for (i=0;i <= (len_of_text - len_of_pattern);i++) {
        j = 0;
        while ((j < len_of_pattern) && (pattern[j] == text[i+j])) {
            j++;
        }
        if (j == len_of_pattern) {
            return i+1;
        }
    }
    return -1;
}
