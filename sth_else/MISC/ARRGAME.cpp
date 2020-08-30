/**
 * ARRGAME - https://www.codechef.com/LTIME87B/problems/ARRGAME
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  long long T; cin >> T;
  while (T--) {
    long long N; cin >> N;
    vector<long long>A; for (long long i = 1; i <= N; ++i) {long long u; cin >> u; A.push_back(u);}
    vector<long long>B;

    long long L = 0;
    for (long long i = 0; i < N; ++i) {
      if (A[i] == 0) ++L;
      else {
        if (L != 0) {
          B.push_back(L);
          L = 0;
        }
      }
    }

    if (B.size() == 0) cout << "No" << endl;
    else {
      if (B.size() == 1) {
        cout << ((B[0] % 2 == 0) ? "No" : "Yes") << endl;
      }
      else {
        sort(B.begin(), B.end(), greater<long long>());

        if (B[1] > B[0] / 2) cout << "No" << endl;
        else if (B[0] % 2 == 0) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
    }
  }

  return 0;
}
