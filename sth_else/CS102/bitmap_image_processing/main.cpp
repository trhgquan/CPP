/**
 * Bai tap tuan 06 - Ky thuat Lap trinh.
 *
 * This program split an BMP image into w*h size images.
 *
 * Code by Tran Hoang Quan - 19120338.
 * GitHub: @trhgquan - https://github.com/trhgquan
 */

#include"bmp.h"

int main(int argc, char** argv) {
	int SAMPLE_PART_HEIGHT = 1, SAMPLE_PART_WIDTH = 1;
	char* filePath = NULL;

	bool hasErrors = 0;

	switch (argc) {
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
			printf("Too less arguments!\n");
			hasErrors = 1;
	}

	if (SAMPLE_PART_HEIGHT <= 0 || SAMPLE_PART_WIDTH <= 0) {
		hasErrors = 1;
		printf("Parts must larger than 0\n");
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

		printf("File written successfully.\n");

		// Release memory.
		releaseBMPPixelArray(bmp);
	}
	return 0;
}
