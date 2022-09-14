/**
 * PLAYSTR - https://codechef.com/problems/PLAYSTR
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a, b;
        cin >> a; cin >> b;
        vector<int> c = {0,0};
        for(int i = 0;i < n; ++i){
            if (a[i] == '1') c[0]++;
            if (b[i] == '1') c[1]++;
        }
        if (c[0] == c[1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
