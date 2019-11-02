/**
 * HYPNOS - Happy Numbers I
 * https://www.spoj.com/problems/HPYNOS/
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> e;
    int n; cin >> n;
    int s = 0, c = 0;
    while (true) {
        while (n > 0) {
            s += (n % 10) * (n % 10);
            n /= 10;
        }
        c++;
        if (s == 1) {
            cout << c << endl;
            break;
        } else {
            // Binary search
            sort(e.begin(), e.end());
            if (binary_search(e.begin(), e.end(), s)) {
                cout << -1 << endl;
                break;
            }
            e.push_back(s);
            n = s;
            s = 0;
        }
    }
    return 0;
}
