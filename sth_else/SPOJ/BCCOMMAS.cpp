/**
 * BCCOMMAS - https://www.spoj.com/PTIT/problems/BCCOMMAS
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long N; cin >> N;
    vector<int>num;
    while (N > 0) {
        num.push_back(N % 10); N /= 10;
    }

    vector<char>result;
    int count = 0;
    for (unsigned i = 0; i < num.size(); ++i) {
        if (count == 3) {result.push_back(','); count = 0;}
        ++count; result.push_back(num[i] + 48);
    }

    for (unsigned i = result.size() - 1; i > 0; --i) cout << result[i];
    cout << result[0];
    return 0;
}
