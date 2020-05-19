/**
 * This program duplicates a string,
 * concats it into the original string
 * and print the result string to the screen.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char original_string[] = "@trhgquan - https://github.com/trhgquan";

    // Duplicates a string.
    // This is a memory-allocated string.
    char* duplicated_string = strdup(original_string);

    printf("Original string: \"%s\"\n", original_string);
    printf("Duplicated string: \"%s\"\n", duplicated_string);

    // Create a third memory-allocated string.
    // to store concatenated string.
    // Remember that this string must have the length of first string + second string.
    char* concat_string = (char*)malloc(strlen(original_string) + strlen(duplicated_string) + 1);

    // At this point, if we continue to use the allocated memory
    // will result in your result string have some extra characters
    // at the beginning.
    // (Do a small test by comment row 34)/
    // This is because the allocated string DOES NOT empty at all.
    // Give it a NULL at the beginning, and everything will be alright.
    concat_string[0] = '\0';

    // Concating..
    strcat(concat_string, original_string);
    strcat(concat_string, duplicated_string);
    printf("Concatenated string: \"%s\"\n", concat_string);

    // Free memories at the end.
    free(duplicated_string);
    free(concat_string);
    return 0;
}
