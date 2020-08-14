/**
 * P142SUMG - https://www.spoj.com/PTIT/problems/P142SUMG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    cin.ignore();
    while (T--) {
        string inp; getline(cin, inp);
        map<char, int>count;
        for (unsigned i = 0; i < inp.size(); ++i)
            if (inp[i] != ' ') ++count[inp[i]];

        pair<char, int>max = *count.begin();
        int countMax = 1;
        for (auto it = next(count.begin()); it != count.end(); ++it){
            if (it->second > max.second) {max = *it; countMax = 1;}
            else if (it->second == max.second) ++countMax;
        }

        if (countMax != 1) cout << "NOT POSSIBLE" << endl;
        else {
            int distance;
            if (max.first >= 'E') distance = max.first - 'E';
            else distance = 'Z' - 'E' + 1 + max.first - 'A';

            string res;
            for (unsigned i = 0; i < inp.size(); ++i) {
                if (inp[i] == ' ') res += inp[i];
                else {
                    if (inp[i] - distance >= 'A') res += inp[i] - distance;
                    else res += 'Z' - distance + inp[i] - 'A' + 1;
                }
            }
            cout << distance << ' ' << res << endl;
        }

    }
    return 0;
}
