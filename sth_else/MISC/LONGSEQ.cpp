/**
 * LONGSEQ - https://codechef.com/problems/LONGSEQ
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while (T--) {
        string s; cin >> s;
        int l = s.size() - 1;
        vector<int> a = {0, 0};
        for (char i: s) a[int(i) - 48]++;
        if ((a[0] == 1 && a[1] == l) ||
            (a[1] == 1 && a[0] == l))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
