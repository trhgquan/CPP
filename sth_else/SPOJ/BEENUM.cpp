/**
 * BEENUM - https://www.spoj.com/problems/BEENUM
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    set<ll>beenums; beenums.insert(1);
    vector<ll>sums; sums.push_back(1);
    for (ll i = 1; i <= 20000; ++i){
        ll calc = 6 * i + sums[i - 1];
        beenums.insert(calc); sums.push_back(calc);
    }
    ll x;
    while (cin >> x) {
        if (x == (ll)-1) break;
        else {
            if (beenums.find(x) != beenums.end()) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}
