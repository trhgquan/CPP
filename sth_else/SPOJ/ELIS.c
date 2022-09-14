/**
 * ELIS - https://vn.spoj.com/problems/ELIS
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include <stdio.h>

int N;
int result;
int A[21];
int F[21];

void Read() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    A[0] = -1;
    F[0] = 0;
}

int main() {
    Read();
    for (int i = 1; i <= N; ++i){
        int jmax = 0;
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && F[j] > F[jmax])
                jmax = j;
        }
        F[i] = F[jmax] + 1;
    }
    result = -1;
    for (int i = 1; i <= N; ++i)
        if (F[i] > result) result = F[i];
    printf("%d", result);
    return 0;
}
