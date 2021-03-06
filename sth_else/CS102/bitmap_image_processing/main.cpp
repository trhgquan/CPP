/**
 * This program split an BMP image into w*h size images.
 * (Week 06 - CS102).
 *
 * Code by Tran Hoang Quan - 19120338.
 * GitHub: @trhgquan - https://github.com/trhgquan
 */

#include"bmp.h"

int main(int argc, char** argv) {
    int SAMPLE_PART_HEIGHT = 1, SAMPLE_PART_WIDTH = 1;

    // Path to the .bmp file.
    char* filePath = NULL;

    // Error handling.
    bool hasErrors = 0;

    switch (argc) {
        // filename -w SAMPLE_PART_WIDTH -h SAMPLE_PART_HEIGHT
        // filename -h SAMPLE_PART_HEIGHT -w SAMPLE_PART_WIDTH
        case 6:
            filePath = argv[1];
            if (!strcmp(argv[2], "-h") && !strcmp(argv[4], "-w")) {
                SAMPLE_PART_HEIGHT = atoi(argv[3]);
                SAMPLE_PART_WIDTH = atoi(argv[5]);
            }

            else if (!strcmp(argv[2], "-w") && !strcmp(argv[4], "-h")) {
                SAMPLE_PART_WIDTH = atoi(argv[3]);
                SAMPLE_PART_HEIGHT = atoi(argv[5]);
            }

            else {
                hasErrors = 1;
                printf("Command not found\n");
            }
            break;

        // filename -h SAMPLE_PART_HEIGHT
        // filename -w SAMPLE_PART_WIDTH
        case 4:
            filePath = argv[1];
            if (!strcmp(argv[2], "-h"))
                SAMPLE_PART_HEIGHT = atoi(argv[3]);
            else if (!strcmp(argv[2], "-w"))
                SAMPLE_PART_WIDTH = atoi(argv[3]);
            else {
                hasErrors = 1;
                printf("Command not found");
            }
            break;

        default:
            printf("Too few / many arguments!\n");
            hasErrors = 1;
    }

    // If part size is smaller than zero, return error.
    if (SAMPLE_PART_HEIGHT <= 0 || SAMPLE_PART_WIDTH <= 0) {
        hasErrors = 1;
        printf("Parts must larger than 0\n");
    }

    // If file is not a valid BMP file, return error.
    FILE* f = fopen(filePath, "rb");
    if (!isBMPFile(f)) {
        hasErrors = 1;
        printf("This file is not a valid BMP file.\n");
    }

    if (!hasErrors) {
        BMPFile bmp;

        // Read file.
        readBMPFile(filePath, bmp);

        // Print file info.
        printBMPHeader(bmp);
        printBMPDIB(bmp);

        // Write file into files.
        writeBMPFile(bmp, SAMPLE_PART_HEIGHT, SAMPLE_PART_WIDTH);

        printf("Files written successfully.\n");

        // Release memory.
        releaseBMPPixelArray(bmp);
    }
    return 0;
}
