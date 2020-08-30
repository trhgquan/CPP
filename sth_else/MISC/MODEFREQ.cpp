/**
 * MODEFREQ - https://www.codechef.com/LTIME87B/problems/MODEFREQ
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    map<int, int>count;
    for (int i = 1; i <= N; ++i) {int u; cin >> u; ++count[u];}
    map<int, int>frequency;
    for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
      ++frequency[it->second];

    int mostFrequency = 0;
    int res = 0;
    for (map<int, int>::iterator it = frequency.begin(); it != frequency.end(); ++it)
      if (it->second > mostFrequency) {res = it->first; mostFrequency = it->second;}

    cout << res << endl;
  }

  return 0;
}
