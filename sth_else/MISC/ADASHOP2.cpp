/**
 * ADASHOP2 - https://www.codechef.com/MARCH20B/problems/ADASHOP2
 * Codechef March Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Okay, just think simple about this problem:
    // We can visit each cells for number of steps < 64 steps,
    // that means we can visit them diagonally.
    // So what is the minimum number of diagon lines we need?

    int T; cin >> T;
    while (T--) {
        int r, c; cin >> r >> c;
        vector<pair<int, int>>route;

        if (r != 1 || c != 1) {
            if (r > c) {
                for (int i = 1; i <= 8; ++i)
                    if (r - i == c + i){
                        r = r - i;
                        c = c + i;
                        break;
                    }
            } else if (r < c) {
                for (int i = 1; i <= 8; ++i)
                    if (r + i == c - i){
                        r = r + i;
                        c = c - i;
                        break;
                    }
            }
            route.push_back(pair<int, int>(r, c));
        }

        // Codes above is to move the bishop to the main diagonal.
        // That's correct! Minimum 26 lines, and maximum 27 lines.
        // The situation that leads to 27 lines only happend, if we didn't stand at the main diagon line (aka x = y) at the beginning.

        route.push_back(pair<int, int>(1, 1));
        int count = 1;
        for (int i = 2; i <= 7; ++i) {
            route.push_back(pair<int, int>(i, i));
            route.push_back(pair<int, int>(i - count, i + count));
            route.push_back(pair<int, int>(i + count, i - count));
            route.push_back(pair<int, int>(i, i));
            if (count < 3) ++count;
            else count = -3;
        }
        route.push_back(pair<int, int>(8, 8));

        cout << route.size() << endl;
        for (unsigned i = 0; i < route.size(); ++i)
            cout << route[i].first << ' ' << route[i].second << endl;
    }
    return 0;
}
