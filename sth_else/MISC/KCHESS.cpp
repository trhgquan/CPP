/**
 * KCHESS - https://codechef.com/problems/KCHESS
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        set<pair<long, long>>chessboard;
        int N; cin >> N;
        for (int i = 1; i <= N; ++i) {
            long u, v; cin >> u >> v;
            chessboard.insert({u + 2, v + 1});
            chessboard.insert({u + 2, v - 1});
            chessboard.insert({u - 2, v + 1});
            chessboard.insert({u - 2, v - 1});
            chessboard.insert({u + 1, v + 2});
            chessboard.insert({u - 1, v + 2});
            chessboard.insert({u - 1, v - 2});
            chessboard.insert({u + 1, v - 2});
        }

        long x, y; cin >> x >> y;
        bool isCheckmate = false;
        if (chessboard.find({x, y}) != chessboard.end()) {
            // In checkmate
            int xD[8] = {1, 1, 0, -1, -1, -1, 0, 1};
            int yD[8] = {1, 0, 1, -1,  1, 0, -1, -1};

            bool canEscape = false;
            for (int i = 0; i < 8; ++i) {
                if (chessboard.find({x + xD[i], y + yD[i]}) == chessboard.end())
                    {canEscape = true; break;}
            }

            if (!canEscape) isCheckmate = true;
        }

        if (isCheckmate) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
