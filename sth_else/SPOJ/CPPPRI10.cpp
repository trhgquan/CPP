/**
 * CPPPRI10 - https://www.spoj.com/PTIT/problems/CPPPRI10
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

long sumDigits(long a) {
    long res = 0;
    while (a > 0) {res += a % 10; a /= 10;}
    return res;
}

int isPrime(long a) {
    if (a == 2) return 1;
    if (a < 2) return 0;
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        vector<long>elements;
        long N; cin >> N;
        long M = N;
        long count = 2;
        while (M > 1) {
            if (M % count == 0) {
                elements.push_back(count); M /= count;
            } else ++count;
        }
        long sum = 0;
        for (unsigned long i = 0; i < elements.size(); ++i)
            sum += sumDigits(elements[i]);

        if (sum == sumDigits(N) && !isPrime(N)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
