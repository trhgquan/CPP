/**
 * SWPDGT - https://www.codechef.com/problems/SWPDGT
 * Codechef March Lunchtime 2020 - Division 2
 * (Contest ended due to system cannot handle too many users at the same time).
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int A, B; cin >> A >> B;
        int res = A + B;
        if (A >= 10 && B >= 10) {
            int first = A / 10;
            int second = A % 10;
            int third = B / 10;
            int last = B % 10;

            if (first * 10 + third + second * 10 + last > res)
                res = first * 10 + third + second * 10 + last;
            if (last * 10 + second + third * 10 + first > res)
                res = last * 10 + second + third * 10 + first;
        }

        else if ((A >= 10 && B < 10) ||
            (A < 10 && B >= 10)) {
            if (A < 10 && B >= 10) {
                int C = A;
                A = B;
                B = C;
            }

            int first = A / 10;
            int second = A % 10;
            int third = B;

            if (third * 10 + second + first > res)
                res = third * 10 + second + first;
        }

        cout << res << endl;
    }

    return 0;
}
