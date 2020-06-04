/**
 * Bai tap tuan 06 - Ky thuat Lap trinh.
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

struct BMPSignature {
    unsigned char data[2];
};

struct BMPHeader {
    BMPSignature signature;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
};

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

struct Color {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

struct colorTable {
    Color* colors;
    uint32_t length;
};

struct pixelArray {
    unsigned char* rawBytes;
    int rawByteSize;
    int lineSize;
    char paddingSize;

    Color** pixels;
    uint32_t rowCount;
    uint32_t columnCount;
};

struct BMPFile {
    BMPHeader header;
    BMPDIB dib;
    colorTable table;
    pixelArray array;
};

#pragma pack(pop)

bool isBMPFile(FILE*);

void readBMPHeader(FILE*, BMPFile&);
void readBMPDIB(FILE*, BMPFile&);

void readBMPPixelArray(FILE*, BMPFile&);
void initPixels(pixelArray&, int, int);

void readBMPFile(char*, BMPFile&);

void printBMPHeader(BMPFile);
void printBMPDIB(BMPFile);
void drawBMP(BMPFile);

void writeBMPFile(BMPFile, int, int);

void releaseBMPPixelArray(BMPFile&);
