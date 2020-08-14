/**
 * P144PROD - https://www.spoj.com/PTIT/problems/P144PROD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

string generateZeros(int size) {
    string res;
    for (int i = 1; i <= size; ++i) res += '0';
    return res;
}

string removeZeros(string a) {
    while (*a.begin() == '0') a.erase(a.begin());
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int count = 0;
    while (true) {
        ++count;
        int N; cin >> N;
        if (N == 0) break;
        set<string>m;
        vector<string>s;
        bool can = true;
        unsigned max_length = 0;

        for (int i = 1; i <= N; ++i) {
            string x; cin >> x; s.push_back(x);
            if (x.size() > max_length) max_length = x.size();
        }

        for (int i = 0; i < N; ++i) {
            if (s[i].size() < max_length) s[i] = generateZeros(max_length - s[i].size()) + s[i];
            m.insert(s[i]);
        }

        if (m.size() == 1) can = false;

        cout << "Case " << count << ": ";
        if (!can) cout << "There is a row of trees having equal height." << endl;
        else cout << removeZeros(*m.begin()) << " " << removeZeros(*prev(m.end())) << endl;
    }
    return 0;
}
