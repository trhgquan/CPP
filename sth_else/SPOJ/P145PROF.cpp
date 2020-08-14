/**
 * P145PROF - https://www.spoj.com/PTIT/problems/P145PROF
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    map<pair<int, int>, int>time;
    while (N--) {
        int h, m; cin >> h >> m;
        map<pair<int, int>, int>::iterator it = time.find({h, m});
        if (it == time.end()) time.insert(pair<pair<int, int>, int>({h, m}, 1));
        else ++it->second;
    }
    int max = 1;
    for (auto it = time.begin(); it != time.end(); ++it)
        if (it->second > max) max = it->second;
    cout << max;
    return 0;
}
