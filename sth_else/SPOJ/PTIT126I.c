/**
 * PTIT126I - https://www.spoj.com/PTIT/problems/PTIT126I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char A[51], B[51]; scanf("%s%s", A, B);
    unsigned x, y;

    // Find the first common character
    int found = 0;
    for (x = 0; x < strlen(A); ++x){
        for (y = 0; y < strlen(B); ++y)
            if (A[x] == B[y]) {found = 1; break;}
        if (found) break;
    }

    // Create the pattern
    char G[51][51];
    for (unsigned i = 0; i < strlen(B); ++i){
        for (unsigned j = 0; j < strlen(A); ++j){
            if (i == y) G[i][j] = A[j];
            else if (j == x) G[i][j] = B[i];
            else G[i][j] = '.';
        }
    }

    // Print the pattern
    for (unsigned i = 0; i < strlen(B); ++i){
        for (unsigned j = 0; j < strlen(A); ++j){
            printf("%c", G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
