/**
 * P162SUMG - https://www.spoj.com/PTIT/problems/P162SUMG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

void stringToUppercase(char* string) {
    for (unsigned i = 0; i < strlen(string); ++i){
        if (string[i] >= 'a' && string[i] <= 'z') printf("%c", string[i] - 32);
        else printf("%c", string[i]);
    }
}

void stringToLowercase(char* string) {
    for (unsigned i = 0; i < strlen(string); ++i){
        if (string[i] >= 'A' && string[i] <= 'Z') printf("%c", string[i] + 32);
        else printf("%c", string[i]);
    }
}

int main() {
    char string[101]; scanf("%s", string);
    int lower = 0, upper = 0;
    for (unsigned i = 0; i < strlen(string); ++i){
        if (string[i] >= 'A' && string[i] <= 'Z') ++upper;
        else ++lower;
    }

    if (lower >= upper)
        stringToLowercase(string);
    else stringToUppercase(string);
    return 0;
}
