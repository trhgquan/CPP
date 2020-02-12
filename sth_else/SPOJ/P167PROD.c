/**
 * P167PROD - https://www.spoj.com/PTIT/problems/P167PROD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char S[11][11];
    int A[4];
    for (int i = 1; i <= 3; ++i) {
        scanf("%s", S[i]);
        int found = 0;
        for (unsigned j = 0; j < strlen(S[i]); ++j)
            if (S[i][j] == '?') {found = 1; break;}
        if (!found) {
            A[i] = 0;
            for (unsigned j = 0; j < strlen(S[i]); ++j) A[i] = A[i] * 10 + (S[i][j] - 48);
        } else A[i] = -1;
    }

    // Print result
    int Z, L;

    if (A[1] == -1) {
        Z = A[3] - A[2];
        L = strlen(S[1]);
        while (L >= 0) {
            --L;
            if (S[1][L] == '?') {
                printf("%d\n", Z % 10);
                break;
            }
            Z /= 10;
        }
    }

    else if (A[2] == -1) {
        Z = A[3] - A[1];
        L = strlen(S[2]);
        while (L >= 0) {
            --L;

            if (S[2][L] == '?') {
                printf("%d\n", Z % 10);
                break;
            }
            Z /= 10;
        }
    }

    else {
        Z = A[1] + A[2];
        L = strlen(S[3]);
        while (L >= 0) {
            --L;

            if (S[3][L] == '?') {

                printf("%d\n", Z % 10);
                break;
            }

            Z /= 10;
        }
    }

    return 0;
}
