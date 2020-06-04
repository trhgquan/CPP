/**
 * Bai tap tuan 06 - Ky thuat Lap trinh.
 *
 * Code by Tran Hoang Quan - 19120338.
 * GitHub: @trhgquan - https://github.com/trhgquan
 */

#include"bmp.h"

bool isBMPFile(FILE* f) {
    if (f == NULL) return false;

    BMPSignature signature;
    fseek(f, 0, SEEK_SET);
    fread(&signature, sizeof(BMPSignature), 1, f);

    return signature.data[0] == 'B' && signature.data[1] == 'M';
}

void initPixels(pixelArray& pa, int width, int height) {
    pa.rowCount = height;
    pa.columnCount = width;

    pa.pixels = new Color * [pa.rowCount];

    for (int i = 0; i < pa.rowCount; ++i)
        pa.pixels[pa.rowCount - 1 - i] = (Color*)(pa.rawBytes + pa.lineSize * i);
}

void readBMPHeader(FILE* f, BMPFile& bmp) {
    if (f == NULL) return;

    fseek(f, 0, SEEK_SET);
    fread(&bmp.header, sizeof(BMPHeader), 1, f);
}

void readBMPDIB(FILE* f, BMPFile& bmp) {
    if (f == NULL) return;

    fseek(f, sizeof(BMPHeader), SEEK_SET);
    fread(&bmp.dib, sizeof(BMPDIB), 1, f);
}

void readBMPPixelArray(FILE* f, BMPFile& bmp) {
    if (f == NULL) return;

    int widthSize = bmp.dib.imageWidth * (bmp.dib.pixelSize / 8);
    bmp.array.paddingSize = (4 - (widthSize % 4)) % 4;
    bmp.array.lineSize = widthSize + bmp.array.paddingSize;
    bmp.array.rawByteSize = bmp.array.lineSize * bmp.dib.imageHeight;
    bmp.array.rawBytes = new unsigned char[bmp.array.rawByteSize];

    fseek(f, bmp.header.dataOffset, SEEK_SET);
    fread(bmp.array.rawBytes, bmp.array.rawByteSize, 1, f);

    initPixels(bmp.array, bmp.dib.imageWidth, bmp.dib.imageHeight);
}

void releaseBMPPixelArray(BMPFile& bmp) {
    delete[]bmp.array.rawBytes;
    delete[]bmp.array.pixels;
}

void printBMPHeader(BMPFile bmp) {
    BMPHeader header = bmp.header;

    printf("*** BMP Header ***\n");
    printf("- File Size  : %d byte(s)\n", header.fileSize);
    printf("- Reserved1  : %d\n", header.reserved1);
    printf("- Reserved2  : %d\n", header.reserved2);
    printf("- Data Offset: %d byte(s)\n", header.dataOffset);
    printf("\n");
}

void printBMPDIB(BMPFile bmp)
{
    BMPDIB dib = bmp.dib;

    printf("*** BMP Dib ***\n");
    printf("- DIB Size               : %d byte(s)\n", dib.dibSize);
    printf("- Image Width            : %d\n", dib.imageWidth);
    printf("- Image Height           : %d\n", dib.imageHeight);
    printf("- Number of Color Planes : %d\n", dib.colorPlaneCount);
    printf("- Pixel Size             : %d bit(s)\n", dib.pixelSize);
    printf("- Compress Method        : %d\n", dib.compressMethod);
    printf("- Bitmap Size            : %d byte(s)\n", dib.bitmapByteCount);
    printf("- Horizontal Resolution  : %d\n", dib.horizontalResolution);
    printf("- Vertical Resolution    : %d\n", dib.verticalResolution);
    printf("- Number of Colors       : %d\n", dib.colorCount);
    printf("- Number of Impt Colors  : %d\n", dib.importantColorCount);
    printf("\n");
}

void drawBMP(BMPFile bmp) {
    HWND console = GetConsoleWindow();
    HDC hdc = GetDC(console);

    for (int i = 0; i < bmp.dib.imageHeight; ++i) {
        for (int j = 0; j < bmp.dib.imageWidth; ++j) {
            Color pixel = bmp.array.pixels[i][j];
            SetPixel(hdc, j, i, RGB(pixel.red, pixel.green, pixel.blue));
        }
    }

    ReleaseDC(console, hdc);
}

void writeBMPFile(BMPFile bmp, int SAMPLE_PART_HEIGHT, int SAMPLE_PART_WIDTH) {
    BMPFile originalBMP = bmp;

    // Calculate new image size.
    int newHeight = bmp.dib.imageHeight / SAMPLE_PART_HEIGHT;
    int newWidth  = bmp.dib.imageWidth  / SAMPLE_PART_WIDTH;

    // Set new image size for new image.
    bmp.dib.imageHeight = newHeight;
    bmp.dib.imageWidth  = newWidth;

    int count = 0;
    int lastPixelI = 0, lastPixelJ = 0;
    while (count < SAMPLE_PART_HEIGHT * SAMPLE_PART_WIDTH) {
        // Create file name
        char fileName[sizeof("100000000.bmp")];
        sprintf(fileName, "%d.bmp", count + 1);

        // Open file
        FILE* f = fopen(fileName, "wb+");

        // Write header and dib.
        fwrite(&bmp.header, sizeof(BMPHeader), 1, f);
        fwrite(&bmp.dib, sizeof(BMPDIB), 1, f);

        // Write pixels.
        for (int i = lastPixelI; i < lastPixelI + newHeight; ++i) {
            for (int j = lastPixelJ; j < lastPixelJ + newWidth; ++j) {
                Color pixel = originalBMP.array.pixels[originalBMP.dib.imageHeight - i - 1][j];

                fwrite(&pixel.blue, sizeof(pixel.blue), 1, f);
                fwrite(&pixel.green, sizeof(pixel.green), 1, f);
                fwrite(&pixel.red, sizeof(pixel.red), 1, f);
            }
        }

        if (lastPixelJ < originalBMP.dib.imageWidth) lastPixelJ += newWidth;
        if (lastPixelJ == originalBMP.dib.imageWidth) {
            if (lastPixelI < originalBMP.dib.imageHeight) {
            lastPixelI += newHeight;
            lastPixelJ = 0;
            } else {
                fclose(f);
                break;
            }
        }

        ++count;
        // Close file.
        fclose(f);
    }
}

void readBMPFile(char* fileName, BMPFile& bmp) {
    FILE* f = fopen(fileName, "rb");
    if (f == NULL || !isBMPFile(f)) {
        printf("Error or Invaid BMP file\n");
        return;
    }

    readBMPHeader(f, bmp);
    readBMPDIB(f, bmp);
    readBMPPixelArray(f, bmp);

    fclose(f);
}
