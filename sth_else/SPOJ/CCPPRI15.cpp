/**
 * CCPPRI15 - https://www.spoj.com/PTIT/problems/CCPPRI15
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>PRIME(1000001, 1), sieve, result;
    for (int i = 2; i <= 1000000; ++i)
        for (int j = 2; j * i <= 1000000; ++j)
            if (PRIME[i * j]) PRIME[j * i] = 0;
    for (int i = 2; i <= 1000000; ++i)
        if (PRIME[i]) sieve.push_back(i);
    result.push_back(1);
    for (int i = 2; i <= 1000000; ++i){
        if (PRIME[i]) result.push_back(i);
        else {
            for (unsigned j = 0; j < sieve.size(); ++j)
                if (i % sieve[j] == 0) {
                    result.push_back(sieve[j]);
                    break;
                }
        }
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i = 0; i < N; ++i)
            cout << result[i] << ' ';
        cout << endl;
    }
    return 0;
}
