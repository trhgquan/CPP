/**
 * This program demonstrate how binary file were read / written.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    // Write an integer and a string to file, using binary mode
    // sample data from binary_input.txt
    FILE* fn = fopen("binary_input.txt", "r");
    int x, y; fscanf(fn, "%d", &x); fscanf(fn, "%d", &y);
    char s[101]; fscanf(fn, "%s", s);
    fclose(fn);

    // fwrite(buffer, blockCount, blockSize, file_stream)

    // Open file in write binary mode.
    FILE* fw = fopen("binary_input.dat", "w+b");

    // Write first number
    fwrite(&x, sizeof(int), 1, fw);

    // Write second number
    fwrite(&y, sizeof(int), 1, fw);

    // Write string
    fwrite(s, sizeof(char), strlen(s), fw);

    // Close file
    fclose(fw);

    // Release array
    // free(s);
    return 0;
}
