/**
 * GIFTSRC - https://www.codechef.com/COOK116B/problems/GIFTSRC
 * Codechef March Cook-off 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

bool notSameAxis(char a, char b) {
    if (a == b) return false;
    return (!(a == 'R' && b == 'L') &&
            !(a == 'L' && b == 'R') &&
            !(a == 'U' && b == 'D') &&
            !(a == 'D' && b == 'U'));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;
        string res; res += S[0];
        char tmp = S[0];
        for (unsigned i = 1; i < S.size(); ++i)
            if (notSameAxis(S[i], tmp)) {tmp = S[i]; res += S[i];}

        int x = 0, y = 0;
        for (unsigned i = 0; i < res.size(); ++i) {
            if (res[i] == 'L') x -= 1;
            if (res[i] == 'R') x += 1;
            if (res[i] == 'D') y -= 1;
            if (res[i] == 'U') y += 1;
        }

        cout << x << ' ' << y << endl;
    }

    return 0;
}
