/**
 * TOANDFRO - https://spoj.com/problems/TOANDFRO
 * Code by @trghquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string reverse(string s) {
    string r = "";
    for (char i: s) r = i + r;
    return r;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; int l;
    while (true) {
        vector<string> g;
        cin >> l;
        if (l == 0) break;
        cin >> s;
        for (unsigned i = 0; i + l <= s.size(); i += l)
            g.push_back(s.substr(i, l));
        for (unsigned i = 0; i < g.size(); ++i)
            if (i % 2 != 0) g[i] = reverse(g[i]);
        for (int i = 0; i < l; ++i)
            for (unsigned j = 0; j < g.size(); ++j)
                cout << g[j][i];
        cout << endl;
    }
    return 0;
}
