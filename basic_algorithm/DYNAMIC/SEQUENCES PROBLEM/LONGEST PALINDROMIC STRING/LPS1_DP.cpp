/**
 * LPS1 - Longest Palindromic Subsequence
 * (This approach using DP (Dynamic Programming) approach, return the longest palindromic subsequence length,
 * aka the longest series of characters, which does not need to be adjacent,
 * forming a palindromic string).
 * Source: https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("LPS.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s; int N = s.length();
    std::vector<vector<int>>L(N, vector<int>(N));

    for (int i = 0; i < N; ++i) L[i][i] = 1;

    int res = 0;

    for (int k = 2; k <= N; ++k) {
        for (int i = 0; i < N - k + 1; ++i) {
            int j = i + k - 1;

            if (s[i] == s[j] && k == 2) L[i][j] = 2;
            else if (s[i] == s[j]) L[i][j] = L[i + 1][j - 1] + 2;
            else L[i][j] = max(L[i + 1][j], L[i][j - 1]);

            if (L[i][j] > res) res = L[i][j];
        }
    }

    cout << "Length of the longest palindromic subsequence, using DP method: " << res;
    return 0;
}
