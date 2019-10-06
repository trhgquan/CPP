// PROBLEM:
// https://vn.spoj.com/problems/QBMAX/
// (Dynamic Programming)

#include <stdio.h>
#include <limits.h>

int m, n;
int F[102][102];
int answer = INT_MIN;

int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

void Read() {
    FILE *fo = fopen("QBMAX.inp", "r+");
    fscanf(fo, "%d %d", &m, &n);
    // scanf("%d %d", &m, &n);

    for (int i = 0; i <= m + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
            F[i][j] = INT_MIN;

    // for (int i = 1; i <= m; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         scanf("%d", &F[i][j]);

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            fscanf(fo, "%d", &F[i][j]);

    fclose(fo);
}

void findMaxPath() {
    for (int j = 2; j <= n; ++j)
        for (int i = 1; i <= m; ++i)
            F[i][j] += max(F[i][j - 1], F[i + 1][j - 1], F[i - 1][j - 1]);

    for (int i = 1; i <= m; ++i)
        if (F[i][n] > answer) answer = F[i][n];

    printf("%d", answer);
}

int main() {
    Read();
    findMaxPath();
    return 0;
}
