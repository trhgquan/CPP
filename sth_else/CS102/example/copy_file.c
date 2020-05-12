/**
 * Copy file from a file to another file,
 * filenames come from keyboard.
 *
 * Notice that I used fprintf and printf separately
 * to print console and write files.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024 * 4 // 4 kilobytes each time

int getFileSize(char* file_source) {
    int fileSize = 0;


    FILE* f = fopen(file_source, "rb"); // Open file
    fseek(f, 0, SEEK_END);              // move the pointer to end of file.
    fileSize = ftell(f);                // get current file pointer, also file size.
    fclose(f);

    return fileSize;
}

/**
 * This function read file_source and file_destination from keyboard.
 *
 * @param file_source      File to copy
 * @param file_destination Destination to copy.
 */
void readFile(char* file_source, char* file_destination) {
    printf("Source file: "); gets(file_source);
    printf("Destination file: "); gets(file_destination);
}

/**
 * Print file informations
 *
 * @param file_source      File to copy
 * @param file_destination Destination to copy.
 */
void fileInformation(char* file_source, char* file_destination) {
    printf("-----\n");
    printf("Source file: %s, file size: %d\n", file_source, getFileSize(file_source));
    printf("Destination file: %s\n", file_destination);
}

/**
 * This function copy a file to another file by reading all characters
 * and copy it to the destination file.
 *
 * Notice that the file_source must exist,
 * while the file_destination will be automatically created
 * if doesn't exist.
 *
 * @param file_source      File to copy
 * @param file_destination Destination to copy.
 */
void copyFile(char* file_source, char* file_destination) {
    FILE* source_pointer = fopen(file_source, "rb");

    if (source_pointer == NULL) printf("Source file doesn't exist. Program stopped, copy nothing.\n");
    else {
        printf("Source file found.\n");
        printf("Copying file..\n");

        // Open destination file, create new file if destination file doesn't exist.
        FILE* destination_pointer = fopen(file_destination, "wb+");

        // Copy each byte from source file to destination file
        // Remember we are using binary-reading and writing mode.
        char content[BUFFER_SIZE]; int blockSize;

        // Code below is another version, but shorter.
        while ((blockSize = fread(content, 1, BUFFER_SIZE, source_pointer)))
            fwrite(content, 1, blockSize, destination_pointer);

        printf("Finished\n");

        // Close the original and destination file.
        fclose(source_pointer); fclose(destination_pointer);
    }
}

int main() {
    // Declare file name variables.
    char* file_source = (char*)malloc(101);
    char* file_destination = (char*)malloc(101);

    // User type the filename
    readFile(file_source, file_destination);

    // Inform user the source file & destination file name.
    fileInformation(file_source, file_destination);

    // Attempts to verify that source are exist.
    copyFile(file_source, file_destination);

    // Free allocated memories.
    free(file_source); free(file_destination);
    return 0;
}
