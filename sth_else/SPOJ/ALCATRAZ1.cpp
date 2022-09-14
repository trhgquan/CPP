/**
 * ALCATRAZ1 - https://www.spoj.com/problems/ALCATRAZ1
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T; string s; int sum;
    while (T--) {
        cin >> s; sum = 0;
        for (char i: s) sum += i - 48;
        cout << sum << endl;
    }
    return 0;
}
