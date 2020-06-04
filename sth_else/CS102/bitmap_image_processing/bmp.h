/**
 * Bitmap Image Processing,
 * (Week 06 - CS102).
 *
 * Code by Tran Hoang Quan - 19120338.
 * GitHub: @trhgquan - https://github.com/trhgquan
 */

#pragma once
#ifndef BMP_H
#define BMP_H
#endif // !BMP_H

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<Windows.h>

#pragma pack(push, 1)

/**
 * This struct stores the signature of a BMP file.
 * aka "BM" at the beginning.
 */
struct BMPSignature {
    unsigned char data[2];
};

/**
 * This struct stores the header of a BMP file.
 */
struct BMPHeader {
    BMPSignature signature;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
};

/**
 * This struct stores the DIB of a BMP file.
 */
struct BMPDIB {
    uint32_t dibSize;
    int32_t imageWidth;
    int32_t imageHeight;
    uint16_t colorPlaneCount;
    uint16_t pixelSize;
    uint32_t compressMethod;
    uint32_t bitmapByteCount;
    int32_t horizontalResolution;
    int32_t verticalResolution;
    uint32_t colorCount;
    uint32_t importantColorCount;
};

/**
 * This struct stores a BGR (blue-green-red) colour.
 */
struct Color {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

/**
 * This struct stores the colour table of a BMP file.
 */
struct colorTable {
    Color* colors;
    uint32_t length;
};

/**
 * This struct stores pixel array of a BMP file.
 */
struct pixelArray {
    unsigned char* rawBytes;
    int rawByteSize;
    int lineSize;
    char paddingSize;

    Color** pixels;
    uint32_t rowCount;
    uint32_t columnCount;
};

/**
 * This struct stores the BMP file.
 */
struct BMPFile {
    BMPHeader header;
    BMPDIB dib;
    colorTable table;
    pixelArray array;
};

#pragma pack(pop)

/**
 * This function check if a file is a valid BMP file.
 * @param  FILE* pointer to the file.
 * @return       true if the file is a valid BMP file,
 *               false otherwise.
 */
bool isBMPFile(FILE*);

// Functions to read BMP file.

/**
 * This function read the header of a BMP file.
 * @param FILE* pointer to the file.
 * @param BMPFile& reference to the variable stores the BMP file structure.
 */
void readBMPHeader(FILE*, BMPFile&);

/**
 * This function read the DIB of a BMP file.
 * @param FILE* pointer to the file.
 * @param BMPFile& reference to the variable stores the BMP file structure.
 */
void readBMPDIB(FILE*, BMPFile&);

/**
 * This function read the Pixel Array of a BMP file.
 * @param FILE* pointer to the file.
 * @param BMPFile& reference to the variable stores the BMP file structure.
 */
void readBMPPixelArray(FILE*, BMPFile&);

/**
 * This function read a BMP file.
 * @param char* file name.
 * @param BMPFile& reference to the variable stores the BMP file structure.
 */
void readBMPFile(char*, BMPFile&);

/**
 * This function release a BMP Pixel Array.
 * @param BMPFile& reference to BMP variable.
 */
void releaseBMPPixelArray(BMPFile&);

/**
 * This function initialise a Pixel Array.
 * @param pixelArray& reference to the Pixel Array variable.
 * @param int    image width.
 * @param int    image height.
 */
void initPixels(pixelArray&, int, int);

/**
 * This function print a BMP file's header.
 * @param BMPFile variable storing the BMP.
 */
void printBMPHeader(BMPFile);

/**
 * This function print a BMP file's DIB.
 * @param BMPFile variable storing the BMP.
 */
void printBMPDIB(BMPFile);

/**
 * This function draw a BMP image.
 * @param BMPFile variable storing the BMP.
 */
void drawBMP(BMPFile);

/**
 * This function write a BMP variable to multiple images.
 * @param BMPFile variable storing the BMP.
 * @param int parts to cut by height.
 * @param int parts to cut by width.
 */
void writeBMPFile(BMPFile, int, int);
