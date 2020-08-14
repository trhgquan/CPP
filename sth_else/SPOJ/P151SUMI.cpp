/**
 * P151SUMI - https://www.spoj.com/PTIT/problems/P151SUMI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<string, int>match;
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        map<string, int>::iterator it = match.find(s);
        if (it == match.end()) match.insert({s, 1});
        else ++it->second;
    }
    if (match.size() == 1) cout << match.begin()->first;
    else {
        cout << ((match.begin()->second > next(match.begin())->second) ? match.begin()->first : next(match.begin())->first);
    }
    return 0;
}
