/**
 * GCDOPS - https://www.codechef.com/LTIME88B/problems/GCDOPS
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
  int c = a % b;
  while (c > 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

void duyetTrauSolution() {
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int>test; test.push_back(-1);
    for (int i = 1; i <= N; ++i) {
      int u; cin >> u; test.push_back(u);
    }

    bool can = true;
    for (int i = 1; i <= N; ++i) {
      if (i != test[i]) {
        can = false;
        for (int j = 1; j <= N; ++j)
          if (GCD(i, test[j]) == test[i]) {can = true; break;}
      }

      if (!can) break;
    }

    cout << ((can) ? "YES" : "NO") << endl;
  }
}

void quanSatSolution() {
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int>A; A.push_back(-1); for (int i = 1; i <= N; ++i) {int u; cin >> u; A.push_back(u);}

    bool can = true;
    for (int i = 1; i <= N; ++i) if (i % A[i] != 0) {can = false; break;}

    cout << ((can) ? "YES" : "NO") << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // duyetTrauSolution();
  quanSatSolution();

  return 0;
}
