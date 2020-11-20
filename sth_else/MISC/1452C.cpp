/**
 * 1452C - https://codeforces.com/contest/1452/problem/C
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int countSquare = 0;
    int countBracket = 0;
    int res =  0;
    for (char i : s) {
      if (i == '(') ++countBracket;
      if (i == ')' && countBracket) {
        ++res;
        --countBracket;
      }

      if (i == '[') ++countSquare;
      if (i == ']' && countSquare) {
        ++res;
        --countSquare;
      }
    }

    cout << res << endl;
  }

  return 0;
}
