/**
 * HRDSEQ - https://codechef.com/problems/HRDSEQ
 * November Challenge 2019 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>a;

    //
    // So the idea is to build a sieve, that will cost O(n^2)
    // the query is only cost O(n).
    //
    a.push_back(0);
    a.push_back(0);

    for (int i = 2; i <= 150; ++i) {
        int j = i - 1;
        bool found = false;
        for (int k = j - 1; k >= 0; --k) {
            if (a[k] == a[j]) {
                a.push_back(j - k);
                found = true;
                break;
            }
        }
        if (found) continue;
        else a.push_back(0);
    }

    // Query
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int r = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == a[n - 1]) r++;
        cout << r << endl;
    }
    return 0;
}
