/**
 * ALGOPRO6 - https://www.spoj.com/PTIT/problems/ALGOPRO6
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int isLeap(int year) {
    if (year % 4 == 0 && year % 100 != 0) return 1;
    if (year % 400 == 0) return 1;
    return 0;
}

int sumNum(int a) {
    int res = 0;
    while (a > 0) {res += a % 10; a /= 10;}
    return res;
}

int main() {
    // This is the sum of 365 days (without year)
    int magicNumber = 3584;
    int year; scanf("%d", &year);
    if (isLeap(year)) magicNumber += sumNum(29) + 2 + sumNum(year);
    magicNumber += sumNum(year) * 365;
    printf("%d", magicNumber);
    return 0;
}
