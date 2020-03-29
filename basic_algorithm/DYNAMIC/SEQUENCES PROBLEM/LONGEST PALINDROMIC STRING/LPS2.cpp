/**
 * LPS2 - Longest Palindromic Substring - First Approach
 * Source: https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/?ref=lbp
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * Note:
 * - The "Longest Palindromic Subsequence" in this problem
 *   means an adjacent series of characters in a string,
 *   different from what we solve in LPS1(which does NOT need to be adjacent).
 *
 * - In this problem, the whole string is considered its substring.
 *   With other problem define "substring" as a series of adjacent character
 *   and have length < the original string's length, check comments below.
 *
 * - I used unsigned since it is very annoying to get warnings in Atom.
 */

int main() {
    freopen("LPS.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    string res;

    vector<vector<int>>table(s.size(), vector<int>(s.size(), 0));
    unsigned start, maxLength;

    start = 0; maxLength = 1; // Each character is a palindromic substring itself.

    // All substrings length 1 is palindrome
    for (unsigned i = 0; i < s.size(); ++i)
        table[i][i] = 1;

    // Check for palindrome substrings length 2
    for (unsigned i = 0; i < s.size() - 1; ++i)
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }

    // Check for lengths greater than 2. k is length of substring.
    // With problems define "substring" different with the original string,
    // replace k <= s.size() with k < s.size().
    for (unsigned k = 3; k <= s.size(); ++k) {
        // Fix the starting index
        for (unsigned i = 0; i < s.size() - k + 1; ++i) {
            // Get the ending index of substring from starting index i and length k
            unsigned j = i + k - 1;

            // Checking for substring from ith index to jth index if s[i + 1] to s[j - 1] is a palindrome
            if (table[i + 1][j - 1] && s[i] == s[j]) {
                table[i][j] = 1;
                if (k > maxLength) {
                    maxLength = k;
                    start = i;
                }
            }
        }
    }

    // Prunsigned the substring
    cout << "The longest palindromic substring is ";
    for (unsigned i = start; i < start + maxLength; ++i)
        cout << s[i];
    cout << "\nMaximum length is: " << maxLength;
    return 0;
}
