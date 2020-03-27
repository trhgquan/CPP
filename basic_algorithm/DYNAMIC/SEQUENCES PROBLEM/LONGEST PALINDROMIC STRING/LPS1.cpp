/**
 * LPS1 - Longest Palindromic Subsequence
 * (This approach return the longest palindromic subsequence length,
 * aka the longest series of characters, which does not need to be adjacent,
 * forming a palindromic string).
 * Source: https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
 */

#include<bits/stdc++.h>
using namespace std;

// This is the naive recursive approach
int LPS(string sequence, int i, int j) {
    // If there is only 1 character
    if (i == j) return 1;

    // If there are 2 characters and they are same
    if (sequence[i] == sequence[j] && i + 1 == j)
        return 2;

    // If the first and last character match
    if (sequence[i] == sequence[j])
        return LPS(sequence, i + 1, j - 1) + 2;

    return max(LPS(sequence, i, j - 1), LPS(sequence, i + 1, j));
}

int main() {
    freopen("LPS.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; cin >> s;

    // Using naive recursive approach
    cout << "Length of the longest palindromic subsequence, using naive recursive method: " << LPS(s, 0, s.size() - 1) << endl;

    // Using dynamic programming approach

    // Build a table
    vector<vector<int>>table(s.size(), vector<int>(s.size()));
    // String length 1 is a palindrome itself
    for (unsigned i = 0; i < s.size(); ++i) table[i][i] = 1;
    int res = 0; // result
    for (unsigned k = 2; k <= s.size(); ++k) {
        for (unsigned i = 0; i < s.size() - k + 1; ++i) {
            unsigned j = i + k - 1;

            if (s[i] == s[j] && k == 2) table[i][j] = 2;
            else if (s[i] == s[j]) table[i][j] = table[i + 1][j - 1] + 2;
            else table[i][j] = max(table[i + 1][j], table[i][j - 1]);

            if (table[i][j] > res) res = table[i][j];
        }
    }
    cout << "Length of the longest palindromic subsequence, using DP method: " << res;
    return 0;
}
