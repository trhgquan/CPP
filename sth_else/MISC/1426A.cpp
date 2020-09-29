/**
 * 1426A - https://codeforces.com/contest/1426/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

void duyetTrauSolution() {
  int T; cin >> T;
  while (T--) {
    int n, x; cin >> n >> x;
    if (n <= 2) cout << 1 << endl;
    else {
      int thisRoom = 3; int thisFloorRoom = 1; int thisFloor = 2;
      while (thisRoom < n) {
        if (thisFloorRoom == x) {
          ++thisFloor; thisFloorRoom = 1;
        }
        else ++thisFloorRoom;
        ++thisRoom;
      }

      cout << thisFloor << endl;
    }
  }
}

void mathSolution() {
  int T; cin >> T;
  while (T--) {
    int n, x; cin >> n >> x;
    cout << ((n <= 2) ? 1 : ((n - 3) / x) + 2) << endl;;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // duyetTrauSolution();
  mathSolution();

  return 0;
}
