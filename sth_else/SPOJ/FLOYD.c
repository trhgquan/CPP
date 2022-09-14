#include <stdio.h>
#define MAX 10001
long M, N, P;
long C[MAX][MAX];
long T[MAX][MAX];

int main() {
    long u, v, c;

    FILE *f = fopen("FLOYD.inp", "r+");
    fscanf(f, "%ld %ld %ld", &N, &M, &P);
    // scanf("%ld %ld %ld", &N, &M, &P);

    for (long i = 1; i <= N; ++i)
        for (long j = 1; j <= N; ++j)
            if (i == j) C[i][j] = 0;
            else C[i][j] = MAX;

    for (long i = 1; i <= M; ++i) {
        fscanf(f, "%ld %ld %ld", &u, &v, &c);
        // scanf("%ld %ld %ld", &u, &v, &c);
        C[u][v] = c;
        C[v][u] = c;
    }

    for (long i = 1; i <= N; ++i)
        for (long j = 1; j <= N; ++j){
            T[i][j] = j;
            T[j][i] = i;
        }

    for (long k = 1; k <= N; ++k)
        for (long i = 1; i <= N; ++i)
            for (long j = 1; j <= N; ++j)
                if (C[i][j] > C[i][k] + C[k][j]){
                    C[i][j] = C[i][k] + C[k][j];
                    T[i][j] = T[i][k];
                }

    for (long i = 1; i <= P; ++i) {
        long c, s, e;
        fscanf(f, "%ld %ld %ld", &c, &s, &e);
        // scanf("%ld %ld %ld", &c, &s, &e);

        if (c == 1) {
            if (s == e){
                printf("2 %ld %ld\n", s, e);
                continue;
            } else {
                long i = 1;
                long j = s;
                do {
                    i++;
                    j = T[j][e];
                } while (j != e);
                printf("%ld ", i);
                do {
                    printf("%ld ", s);
                    s = T[s][e];
                } while (s != e);
                printf("%ld\n", e);
            }
        } else {
            if (C[s][e] >= 10000001) printf("-1");
            else printf("%ld", C[s][e]);
            printf("\n");
        }
    }

    return 0;
}
