/**
 * QBSTR - https://vn.spoj.com/problems/QBSTR
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<stdio.h>
#include<string.h>

int F[10001][10001];
char xauA[10001];
char xauB[10001];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void Initialize() {
    for (unsigned i = 0; i <= strlen(xauA); ++i)
        F[i][0] = 0;
    for (unsigned i = 0; i <= strlen(xauB); ++i)
        F[0][i] = 0;
}

int main() {
    gets(xauA);
    gets(xauB);
    Initialize();

    for (unsigned i = 1; i <= strlen(xauA); ++i) {
        for (unsigned j = 1; j <= strlen(xauB); ++j) {
            if (xauA[i - 1] == xauB[j - 1])
                F[i][j] = F[i - 1][j - 1] + 1;
            else F[i][j] = max(F[i - 1][j], F[i][j - 1]);
        }
    }

    printf("%d", F[strlen(xauA)][strlen(xauB)]);
    return 0;
}
