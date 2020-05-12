/**
 * This program demonstrates how command-argument are parsed to C program.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main(int argc, char** argv) {
    printf("There are %d arguments parsed.\n", argc);

    if (argc != 1) {
        printf("List of parameters:\n");
        for (int i = 0; i < argc; ++i)
            printf("%s\n", argv[i]);
    }
    return 0;
}
