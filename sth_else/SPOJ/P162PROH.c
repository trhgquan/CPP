/**
 * P162PROH - https://www.spoj.com/PTIT/problems/P162PROH
 * Code by @trhgquan - https://github.com.trhgquan
 */

#include<stdio.h>

int main() {
    int count = 0;
    int D[20001] = {0};
    D[1] = 1;
    for (int i = 1; i <= 10001; ++i){
        D[i] = D[i - 1] + i;
    }

    int X; scanf("%d", &X);

    for (int i = 1; i <= 10001; ++i) {
        if (D[i] <= X){
            ++count;
            X = X - D[i];
        }
        else break;
    }

    printf("%d\n", count);
    return 0;
}
