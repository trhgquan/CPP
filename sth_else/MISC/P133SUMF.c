// PROBLEM:
// https://www.spoj.com/PTIT/problems/P133SUMF/
#include <stdio.h>

// Swap 2 variable, in the simplest way.
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Return the smallest in a, b and c.
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

int main() {
    int SUMF[4];
    int d; // d for difference

    for (int i = 1; i <= 3; ++i)
        scanf("%d", &SUMF[i]);

    // Simple sorting.
    for (int i = 1; i <= 2; ++i)
        for (int j = i; j <= 3; ++j)
            if (SUMF[i] > SUMF[j]) Swap(&SUMF[i], &SUMF[j]);

    d = min((SUMF[2] - SUMF[1]), (SUMF[3] - SUMF[2]), (SUMF[3] - SUMF[1]));

    if (SUMF[2] - SUMF[1] == SUMF[3] - SUMF[2])
        printf("%d", SUMF[3] + d);
    else if (SUMF[2] - SUMF[1] > SUMF[3] - SUMF[2])
        printf("%d", SUMF[1] + d);
    else printf("%d", SUMF[3] - d);

    return 0;
}
