/**
 * MATCHES - https://codechef.com/problems/MATCHES
 * code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t;
    vector<int>m = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    while(t--) {
        int a, b, c, s; cin>>a; cin>>b; c = a + b; s = 0;
        while (c > 0) {s += m[c % 10]; c /= 10;}
        cout << s << endl;
    }
}
