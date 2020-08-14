/**
 * P17QPROB - https://www.spoj.com/PTIT/problems/P17QPROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if (a + b < b + a) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        vector<string>s; int N; cin >> N;
        for (int i = 1; i <= N; ++i) {string a; cin >> a; s.push_back(a);}
        sort(s.begin(), s.end(), compare);
        string res = "";
        for (int i = 0; i < N; ++i) res += s[i];
        cout << res << endl;
    }
    return 0;
}
