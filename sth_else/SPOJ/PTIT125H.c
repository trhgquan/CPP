/**
 * PTIT125H - https://www.spoj.com/PTIT/problems/PTIT125H
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    char seats[51]; scanf("%s", seats);
    int count = 0; int hasL = 0;
    for (int i = 0; i < N; ++i) {
        if (seats[i] == 'S') ++count;
        else { hasL = 1; ++count; ++i; }
    }
    if (hasL) ++count;
    printf("%d", count);
    return 0;
}
