/**
 * BCSINH - https://www.spoj.com/PTIT/problems/BCSINH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void Try(int i, int n, int* X) {
    for (int j = 0; j <= 1; ++j){
        X[i] = j;
        if (i == n) {
            // Print the result
            for (int k = 1; k <= n; ++k) printf("%d", X[k]);
            printf("\n");
        } else Try(i + 1, n, X);
    }
}

int main() {
    // Solution goes here
    int X[11]; int n;
    scanf("%d", &n);; Try(1, n, X);
    return 0;
}
