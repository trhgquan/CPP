/**
 * P153PROG - https://www.spoj.com/PTIT/problems/P153PROG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull N, K, D; cin >> N >> K;
    if (N % 2 == 0)
        D = N / 2;
    else D = N / 2 + 1;

    if (K <= D) cout << 1 + (K - 1) * 2;
    else cout << 2 + (K - D - 1) * 2;
    return 0;
}
