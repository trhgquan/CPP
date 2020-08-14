/**
 * P194SUMH - https://www.spoj.com/PTIT/problems/P194SUMH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int productDigits(int a);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    // The problem is, 0 is not a positive integer.
    // So 0 must be represented as a product of 2 integer.
    if (N == 0) cout << 10;
    else if (N < 10) cout << N;
    else {
        stack<int>digits;
        for (int i = 9; i > 1 && N > 1; --i) {
            while (N % i == 0){
                digits.push(i);
                N /= i;
            }
        }

        if (N != 1) cout << -1;
        else {
            int res = 0;
            while (!digits.empty()) {res = res * 10 + digits.top(); digits.pop();}
            cout << res;
        }
    }

    // There is another way, without using stack,
    // but of course cost your time.
    // int N; scanf("%d", &N);
    //
    // if (N == 0) printf("10");
    // else if (N < 10) printf("%d", N);
    // else {
    //     int res = 0; int found = 0;
    //     // Since 6! = 720 > 600, we can make 123456 is the biggest num to check
    //     for (int i = 11; i <= 123456; ++i)
    //         if (productDigits(i) == N) {res = i; found = 1; break;}
    //
    //     if (found) printf("%d", res);
    //     else printf("-1");
    // }
    return 0;
}

int productDigits(int a) {
    int res = 1;
    while (a > 0) {res *= a % 10; a /= 10;}
    return res;
}
