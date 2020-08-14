/**
 * P145PROC - https://www.spoj.com/PTIT/problems/P145PROC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // I use 2 method: vector + binary search and map.
    // Overall, using vector + binary search seems faster with this problem, since inputs are small.

    // This using vector and binary search
    // vector<int>distinct;
    // for (int i = 1; i <= 10; ++i) {
    //     int u; cin >> u; u %= 42;
    //     if (!binary_search(distinct.begin(), distinct.end(), u)){
    //         distinct.push_back(u);
    //         sort(distinct.begin(), distinct.end());
    //     }
    // }

    // This using map.
    map<int, int>distinct;
    for (int i = 1; i <= 10; ++i) {
        int u; cin >> u; u %= 42;
        map<int, int>::iterator it = distinct.find(u);
        if (it == distinct.end()) distinct.insert(pair<int, int>(u, 1));
    }

    // This to print the result.
    cout << distinct.size();
    return 0;
}
