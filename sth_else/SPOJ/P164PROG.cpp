/**
 * P164PROG - https://www.spoj.com/PTIT/problems/P164PROG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define maxLevel 40
using namespace std;

int main() {
    vector<int>pyramid, levels; pyramid.push_back(0); levels.push_back(0);
    for (int i = 1; i <= maxLevel; ++i) pyramid.push_back(pyramid[i - 1] + i);
    for (int i = 1; i <= maxLevel; ++i) levels.push_back(pyramid[i] + levels[i - 1]);
    int N; cin >> N; unsigned i;
    for (i = 1; i < pyramid.size(); ++i)
        if (levels[i] > N) break;
    cout << i - 1 << endl;
    return 0;
}
