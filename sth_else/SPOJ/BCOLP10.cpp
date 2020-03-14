/**
 * BCOLP10 - https://www.spoj.com/PTIT/problems/BCOLP10
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string A, B; cin >> A >> B;
    vector<int>count(26, 0);
    for (char c : A) count[c - 'a']++;
    for (char c : B) count[c - 'a']--;
    int result = 0;
    for (int i = 0; i < 26; ++i) result += abs(count[i]);
    cout << result;
    return 0;
}
