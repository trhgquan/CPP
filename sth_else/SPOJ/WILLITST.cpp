/**
 * WILLITST - https://www.spoj.com/problems/WILLITST
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n; cin >> n;
    while (n % 2 == 0) n /= 2;
    if (n == 1) cout << "TAK" << endl;
    else cout << "NIE" << endl;
    return 0;
}
// #include<stdio.h>
//
// int main() {
//     long long int n; scanf("%lli", &n);
//     while (n % 2 == 0) n /= 2;
//     if (n == 1) printf("TAK\n");
//     else printf("NIE\n");
//     return 0;
// }
