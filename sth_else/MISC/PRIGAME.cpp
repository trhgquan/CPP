/**
 * PRIGAME - https://codechef.com/FEB21C/problems/PRIGAME
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  // Create a sieve.
  vector<int>Eratosthenes(1000001, 1);
  for (int i = 2; i < 1000001; ++i) {
    for (int j = 2; i * j < 1000001; ++j)
      if (Eratosthenes[i * j]) Eratosthenes[i * j] = 0;
  }
  // Using that sieve to create an array counting
  // how many primes are less or equal to x.
  int totalPrimes = 0;
  vector<int>primes = Eratosthenes;
  for (int i = 2; i < 1000001; ++i) {
    if (Eratosthenes[i]) ++totalPrimes;
    primes[i] = totalPrimes;
  }

  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    cout << ((primes[x] > y) ? "Divyam" : "Chef") << '\n';
  }

  return 0;
}
