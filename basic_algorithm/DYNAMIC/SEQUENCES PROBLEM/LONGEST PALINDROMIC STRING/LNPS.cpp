/**
 * LNPS - Longest Non-Palindromic Substring
 * This is however NOT a dynamic programming problem,
 * but marked as a Palindromic Substring problem.
 *
 * In this case, a substring is a series of adjacent characters.
 */

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string a) {
    for (unsigned i = 0; i < a.size() / 2; ++i)
        if (a[i] != a[a.size() - i - 1]) return false;
    return true;
}

bool hasDifferentCharacter(string a) {
    for (unsigned i = 0; i < a.size() - 1; ++i)
        if (a[i] != a[i + 1]) return true;
    return false;
}

int main() {
    freopen("LPS.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    // If a string is not a palindrome itself,
    // LPNS is it.
    if (!isPalindrome(s)) cout << s;
    else {
        // If the string has different character,
        // then the LPNS is the same string removing 1 character
        // at the end / beginning.
        if (hasDifferentCharacter(s)) {
            // Out job now is find which string is greater

            // Get the end-character removed string
            char sEnd = *prev(s.end());
            s.erase(prev(s.end()));
            string removeEnd = s;

            // Get the begin-character removed string
            s += sEnd;
            s.erase(s.begin());
            string removeBegin = s;

            // Print the larger string in Alphabetical Order
            if (removeBegin <= removeEnd)
                cout << removeBegin;
            else cout << removeEnd;
        } else cout << "NO SUCH STRING";
    }
    return 0;
}
