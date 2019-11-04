/**
 * SC31 - https://codechef.com/problems/SC31
 * November Challenge 2019 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, sum; cin >> t;
    string s;
    while (t--) {
        //
        // So the idea is to check, if 2 string nearby has same position is '1'
        // then the sum is 0. Then we check to another nearby string, continue to end.
        //
        vector<int>a(10, 0);
        cin >> n;
        while (n--) {
            cin >> s;
            for (int i = 0; i < 10; ++i)
                if (s[i] == '1' && a[i] == 0) a[i] = 1;
                else if (s[i] == '1' && a[i] == 1) a[i] = 0;
        }
        sum = 0;
        for (int i: a) sum += i;
        cout << sum << endl;
    }
    return 0;
}
