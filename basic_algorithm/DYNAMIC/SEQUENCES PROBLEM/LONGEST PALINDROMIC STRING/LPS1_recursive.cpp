/**
 * LPS1 - Longest Palindromic Subsequence
 * (This approach using recursive approach, return the longest palindromic subsequence length,
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
    cout << "Length of the longest palindromic subsequence, using naive recursive method: " << LPS(s, 0, s.size() - 1);
    return 0;
}
