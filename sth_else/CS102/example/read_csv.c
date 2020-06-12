/**
 * This program read a csv file and print it to the screen.
 * 
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * This function check if a file is a valid .csv or not.
 * @param  fileName file name string.
 * @return          1 if the file is a valid .csv file,
 *                  0 otherwise.
 */
int isCSV(char* fileName) {
    // Get the file name length.
    int lastPos = strlen(fileName);

    // If last 3 characters form ".csv" then this is a valid .csv file,
    // since .csv file doesn't have a signature.
    return fileName[lastPos - 1] == 'v' &&
           fileName[lastPos - 2] == 's' &&
           fileName[lastPos - 3] == 'c';
}

/**
 * This function read a .csv file and print it (non-formatted) to the console.
 * @param f file pointer - r+ mode.
 */
void readCSV(FILE* f) {
    char buffer[1024];

    while (fgets(buffer, 1024, f)) {
        char* cell = strtok(buffer, ",");

        while (cell) {
            printf("%s ", cell);
            cell = strtok(NULL, ",");
        }
        printf("\n");
    }
}

int main() {
    // Get file name from console.
    char fileName[101];

    // File pointer.
    FILE* f = NULL;

    // Read until we found a valid .csv file.
    do {
        printf("File path: "); scanf("%s", fileName);
        FILE* f = fopen(fileName, "r+");
        if (f == NULL)
            printf("File \"%s\" doesn't exist.\n", fileName);
        else if (!isCSV(fileName))
            printf("File \"%s\" is not a valid .csv file.\n", fileName);
        else {
            // File is valid. Read it to the console.
            printf("Reading \"%s\"...\n", fileName);
            readCSV(f);
            break;
        }
    } while (f == NULL || !isCSV(fileName));

    // Close the file.
    fclose(f);

    return 0;
}
