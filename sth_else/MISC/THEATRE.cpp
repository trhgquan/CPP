/**
 * THEATRE - https://codechef.com/problems/THEATRE
 * Codechef February Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int count = 0;
    while (T--) {
        int A[5], B[5], C[5], D[5];
        for (int i = 1; i <= 4; ++i) {A[i] = 0; B[i] = 0; C[i] = 0; D[i] = 0;}

        int N; cin >> N;
        while (N--) {
            char X; int V; cin >> X >> V;
            if (V == 12) V = 1;
            else V = V / 3 + 1;

            if (X == 'A') ++A[V];
            else if (X == 'B') ++B[V];
            else if (X == 'C') ++C[V];
            else ++D[V];
        }

        int max = -400;
        for (int i = 1; i <= 4; ++i){
            for (int j = 1; j <= 4; ++j){
                for (int k = 1; k <= 4; ++k){
                    for (int l = 1; l <= 4; ++l) {
                        if ((i != j && i != k && i != l) &&
                            (j != k && j != l) &&
                            (k != l)){
                            vector<int>test({A[i], B[j], C[k], D[l]});
                            sort(test.begin(), test.end());
                            int cash = 0;
                            for (int i = 0; i < 4; ++i) {
                                if (test[i] == 0) cash -= 100;
                                else cash += (25 * (i + 1)) * test[i];
                            }
                            if (cash > max) max = cash;
                        } else continue;
                    }
                }
            }
        }
        cout << max << endl;
        count += max;
    }
    cout << count << endl;
    return 0;
}
