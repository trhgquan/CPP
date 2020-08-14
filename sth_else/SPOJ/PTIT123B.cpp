/**
 * PTIT123B - https://www.spoj.com/PTIT/problems/PTIT123B
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int caseNum = 0;
    while (true) {
        ++caseNum;
        int N; cin >> N;
        if (N == 0) break;

        vector<int>array; for (int i = 1; i <= N; ++i) {int u; cin >> u; array.push_back(u);}
        vector<int>calc(array.size());
        bool stop = false; bool can = false;
        int count = 0;

        while (!stop && count <= 1000) {
            // Check if we can stop.
            stop = true;
            for (int i = 0; i < N - 1; ++i) if (array[i] != array[i + 1]) {stop = false; break;}
            if (stop && count <= 1000) {can = true; break;}

            // Calculate ABS
            for (int i = 0; i < N - 1; ++i)
                calc[i] = abs(array[i + 1] - array[i]);
            calc[N - 1] = abs(array[N - 1] - array[0]);

            // Match calculated ABS to original array
            for (int i = 0; i < N; ++i) array[i] = calc[i];

            ++count;
        }

        if (can) cout << "Case " << caseNum << ": " << count << " iterations" << endl;
        else cout << "Case " << caseNum << ": not attained" << endl;
    }
    return 0;
}
