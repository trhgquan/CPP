/**
 * A. Common Prefixes - https://codeforces.com/problemset/problem/1384/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        int maxSize = 0;
        vector<int>A; for (int i = 1; i <= N; ++i) {int u; cin >> u; A.push_back(u); if (u > maxSize) maxSize = u;}

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string original = "";

        for (int i = 0; i <= maxSize; ++i){
            if (i < (int)alphabet.size()) original += alphabet[i];
            else original += alphabet[i % (int)alphabet.size()];
        }

        cout << original << endl;
        for (int i = 0; i < N; ++i) {
            if (original[A[i]] == 'z') original[A[i]]--;
            else original[A[i]]++;
            cout << original << endl;
        }
    }

    return 0;
}
