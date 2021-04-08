/**
 * 1504A - https://codeforces.com/contest/1504/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

bool isPalindrome(const string& s) {
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] != s[s.size() - 1 - i]) return 0;

  return 1;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;

    map<char, int>countChar;
    for (char i : s) countChar[i]++;

    if (countChar.size() == 1 && countChar['a'] == (int)s.size()) {
      cout << "NO";
    } else {
      cout << "YES" << '\n';

      string s1, s2; s1 = s2 = s;
      s1.insert(0, "a"); s2.insert(s.size(), "a");

      if (!isPalindrome(s1)) cout << s1;
      else if (!isPalindrome(s2)) cout << s2;
    }

    cout << '\n';
  }

  return 0;
}
