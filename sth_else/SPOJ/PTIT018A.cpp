/**
 * PTIT018A - https://www.spoj.com/PTIT/problems/PTIT018A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>P(1000001, 1); P[1] = 0;
    for (int i = 2; i <= 1000001; ++i)
        for (int j = 2; i * j <= 1000001; ++j) if (P[i * j]) P[i * j] = 0;

    int T; scanf("%d", &T);
    while (T--) {
        int L, R; scanf("%d%d", &L, &R);
        int count = 0;
        for (int i = L; i <= R - 6; ++i)
            if (P[i] && P[i + 6]) ++count;
        printf("%d\n", count);
    }
    return 0;
}
