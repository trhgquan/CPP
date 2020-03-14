/**
 * BCMARA - https://www.spoj.com/PTIT/problems/BCMARA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

typedef struct Run {
    int hours;
    int minute;
    int second;
} Run;

void swap(Run* a, Run* b) {
    Run c = *a;
    *a = *b;
    *b = c;
}

void sort(Run *A, int N) {
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            if (A[i].hours > A[j].hours ||
                (A[i].hours == A[j].hours && A[i].minute > A[j].minute) ||
                (A[i].hours == A[j].hours && A[i].minute == A[j].minute && A[i].second > A[j].second))
                swap(&A[i], &A[j]);
}

int main() {
    int N; scanf("%d", &N);
    Run Runners[N + 1];
    for (int i = 0; i < N; ++i)
        scanf("%d%d%d", &Runners[i].hours, &Runners[i].minute, &Runners[i].second);
    sort(Runners, N);
    for (int i = 0; i < N; ++i)
        printf("%d %d %d\n", Runners[i].hours, Runners[i].minute, Runners[i].second);
    return 0;
}
