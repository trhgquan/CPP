// The Josephus algorithm.
#include <iostream>

#define lli long long int

using namespace std;

lli N, M, C;

lli josephus (lli n, lli m);

void solve () {
    scanf("%I64d %I64d", &N, &M);
    if (N != 0 && M != 0) {
        printf("%I64d %I64d %I64d \n", N, M, josephus(N, M));
        solve();
    }
}

int main() {
    solve();
    return 0;
}

lli josephus (lli n, lli m) {
    lli d = n * m;
    while (d > n)
        d = d + (d - n - 1) / (m - 1) - n;
    return d;
}
