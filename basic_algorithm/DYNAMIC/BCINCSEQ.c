#include <stdio.h>

#define maxLength 100002

long A[maxLength];
int n, F[maxLength];
int max;

void Read() {
    FILE *fp = fopen("BCINCSEQ.inp", "r+");

    fscanf(fp, "%d", &n);
    for (int i = 1; i <= n; ++i)
        fscanf(fp, "%ld", &A[i]);

    // scanf("%d", &n);
    // for (int i = 1; i <= n; ++i)
    //     scanf("%ld", &A[i]);

    fclose(fp);
}

void findLongestSequence() {
    for (int i = 1; i <= n; ++i)
        if (A[i] >= A[i - 1])
            F[i] = F[i - 1] + 1;
        else F[i] = 1;

    max = 1;
    for (int i = 1; i <= n; ++i)
        if (F[i] > max) max = F[i];

    printf("%d", max);
}

int main() {
    Read();
    findLongestSequence();
    return 0;
}
