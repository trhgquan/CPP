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

    // Open file in read binary mode
    FILE* fr = fopen("binary_input.dat", "rb");
    if (fr == NULL) printf("File not opened: cannot find the specific file!\n");
    else {
        // Read and print integer.
        int x; fread(&x, sizeof(int), 1, fr);
        printf("%d ", x);
        int y; fread(&y, sizeof(int), 1, fr);
        printf("%d\n", y);

        // Read a string.
        int blockCount = 11; // strlen of the input string in binary_input.txt
        char* buffer = (char*)malloc(blockCount);
        fread(buffer, sizeof(char), blockCount, fr);
        printf("%s\n", buffer);

        // Close opened file.
        fclose(fr);
        // Free array
        free(buffer);
    }
    return 0;
}
