/**
 * SSAM019K - https://www.spoj.com/PTIT/problems/SSAM019K
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

long sumDigits(long a) {
    long res = 0;
    while (a > 0) {res += a % 10; a /= 10;}
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

    if (sum == sumDigits(N)) cout << "YES";
    else cout << "NO";
    return 0;
}
