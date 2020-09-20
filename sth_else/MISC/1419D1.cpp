/**
 * 1419D1 - https://codeforces.com/contest/1419/problem/D1
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  ll N; cin >> N;
  vector<ll>A; for (int i = 1; i <= N; ++i) {ll u; cin >> u; A.push_back(u);}
  sort(A.begin(), A.end());
  queue<ll>B, C;
  for (int i = 0; i < N / 2; ++i) B.push(A[i]);
  for (int i = N / 2; i < N; ++i) C.push(A[i]);

  cout << ((N % 2 == 0) ? B.size() - 1 : B.size()) << endl;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0 && !C.empty()) {
      A[i] = C.front();
      C.pop();
    }
    else {
      A[i] = B.front();
      B.pop();
    }
  }

  if (N % 2 == 0) {
    ll temp = A[N - 1];
    A[N - 1] = A[N - 2];
    A[N - 2] = temp;
  }

  for (int i = 0; i < N; ++i) cout << A[i] << ' ';

  cout << endl;
  return 0;
}
