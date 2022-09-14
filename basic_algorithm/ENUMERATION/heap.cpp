/**
 * Heap's Algorithm for generating permutations
 *
 * https://en.wikipedia.org/wiki/Heap%27s_algorithm
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * This function print an array to the screen.
 * @param a vector<int>
 */
void printScreen(vector<int> a) {
  for (int i : a) cout << i;
  cout << endl;
}

/**
 * Heap's Algorithm
 * @param a vector<int>&
 * @param k int
 */
void heap(vector<int>& a, int k) {
  if (k == 1) return printScreen(a);
  
  for (int i = 0; i < k - 1; ++i) {
    heap(a, k - 1);
    if (k % 2 == 0) swap(a[i], a[k - 1]);
    else swap(a[0], a[k - 1]);
  }
  
  heap(a, k - 1);
}

int main() {
  freopen("heap.inp", "r+", stdin);
  freopen("heap.out", "w+", stdout);
  vector<int>a; int n;
  cin >> n; for (int i = 0; i < n; ++i) {int u; cin >> u; a.push_back(u);}

  heap(a, a.size());

  return 0;
}
