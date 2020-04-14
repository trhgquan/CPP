/**
 * SQRDSUB - https://www.codechef.com/APRIL20B/problems/SQRDSUB
 * Codechef April long Chalongenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    long T; cin >> T;
    while (T--) {
        long N; cin >> N;
        vector<long>A;
        for (long i = 1; i <= N; ++i) {
            long u; cin >> u; A.push_back(u);
        }

        long total = 0;
        for (long i = 0; i < N; ++i) {
            long ans = 0;
            if (A[i] % 2 == 0 && A[i] % 4 != 0) {
                bool hasLeft = false; bool hasRight = false;
                long countLeft = 0; long countRight = 0;

                for (long j = 1; j + i < N; ++j){
                    if (A[i + j] % 2 != 0) {hasRight = true; ++countRight;}
                    else break;
                }

                for (long j = 1; i - j >= 0; ++j) {
                    if (A[i - j] % 2 != 0) {hasLeft = true; ++countLeft;}
                    else break;
                }

                if (hasLeft && hasRight) {
                    ans = ((countLeft + countRight + 1) * (countLeft + countRight + 2) - (countLeft * (countLeft + 1)) - (countRight * (countRight + 1))) / 2;
                } else {
                    if (hasLeft) ans = countLeft + 1;
                    else if (hasRight) ans = countRight + 1;
                    else ans += 1;
                }
            }

            total += ans;
        }

        cout << (N * (N + 1) / 2) - total << endl;
    }

    return 0;
}
