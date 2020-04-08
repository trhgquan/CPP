/**
 * KPRIMES - https://www.spoj.com/problems/KPRIMES
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
    if (a <= 2) return true;
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    int num = 0;
    while (T--) {
        ++num;
        int N, K; cin >> N >> K;

        vector<bool>exist(N + 1, true);
        for (int i = 1; i <= N; ++i)
            if (isPrime(i)) exist[i] = false;
        for (int i = 1; i <= K; ++i) {
            int P; cin >> P;
            for (int j = 2; j * P <= N; ++j){
                if (exist[j * P])
                    exist[j * P] = false;
            }
        }
        int res = 0; for (int i = 1; i <= N; ++i) res += exist[i];
        cout << "Case " << num << ": " << res << endl;
    }

    return 0;
}
