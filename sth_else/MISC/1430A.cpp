/**
 * 1430A - https://codeforces.com/contest/1430/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

void duyetTrauSolution() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int>res; int can = false;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n - i; ++j) {
        for (int k = 0; k <= n - i - j; ++k){
          if (i * 3 + j * 5 + k * 7 == n) {can = true; res = {i, j, k}; break;}
        }
        if (can) break;
      }
      if (can) break;
    }

    if (can) for (int i : res) cout << i << ' ';
    else cout << -1;
    cout << endl;
  }
}

void sieveSolution() {
  vector<vector<int>>test;
  test.push_back(vector<int>{0, 0, 0});
  for (int i = 1; i <= 1000; ++i) {
    vector<int>check;
    int found = 0;
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= i - j; ++k){
        for (int l = 0; l <= i - j - k; ++l) {
          if (3 * j + 5 * k + 7 * l == i) {
            found = true; check = {j, k, l}; break;}
        }
        if (found) break;
      }
      if (found) break;
    }
    if (!found) check = {-1, 0, 0};
    test.push_back(check);
  }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (test[n][0] == -1) cout << -1;
    else for (int i : test[n]) cout << i << ' ';
    cout << endl;
  }
}

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  duyetTrauSolution();
  // sieveSolution();

  return 0;
}
