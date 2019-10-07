// SPOJ easy version, just output the longest subsequence's length.
// (Dynamic Programming)
#include <stdio.h>
#include <limits.h>
#define NMAX 10001

int n, best;
int F[NMAX], A[NMAX];

void readInputandInitialize() {
    // Input using file
    FILE *f = fopen("LIQ.inp", "r+");
    if (f != NULL) {
        fscanf(f, "%d", &n);
        for (int i = 1; i <= n; ++i)
            fscanf(f, "%d", &A[i]);
    }
    else {
        printf("Input file is not installed. Check and try again.");
    }


    // To normally typing:
    // scanf("%d", &n);
    // for (int i = 1; i <= n; ++i)
    //     scanf("%d", &A[i]);

    // Initialize
    for (int i = 0; i <= n; ++i)
        F[i] = 1;
    F[0] = 0;
    A[0] = INT_MIN;
}

void findLongestIncreasingSubsequence() {
    best = 1; // Longest subsequence length
    for (int i = 1; i <= n; ++i) {
        int jmax = 0;
        for (int j = 0; j < i; ++j)
            if (A[i] > A[j] && F[j] > F[jmax])
                jmax = j;
        F[i] = F[jmax] + 1;
        if (F[i] > best) best = F[i];
    }
    printf("%d", best);
}

int main() {
    readInputandInitialize();
    findLongestIncreasingSubsequence();
    return 0;
}
