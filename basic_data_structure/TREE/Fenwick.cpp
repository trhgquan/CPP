/**
 * Or BIT - Binary Indexed Tree.
 *
 * Sample problem: given an integer array A, sized N.
 * Given q query, each like this u v w.
 *
 * If u = 1, update A[v] = A[v] + w.
 * If u = 2, print the sum from A[v] + A[v + 1] + .. + A[w].
 *
 * Using BIT, we can make this O(logn).
 *
 * For example input, look at Fenwick.txt.
 */
#include<bits/stdc++.h>
using namespace std;

struct Fenwick {
  vector<int>bit;
  int size;

  Fenwick(vector<int>A) {
    this->size = A.size();

    this->bit.push_back(0);
    for (int i = 0; i < this->size; ++i)
      this->bit.push_back(0);

    for (int i = 1; i <= this->size; ++i)
      update(i, A[i - 1]);
  }

  void update(int i, int val) {
    for (; i <= this->size; i += (i & -i)) this->bit[i] += val;
  }

  int query(int i) {
    int res = 0;
    for (; i > 0; i -= (i & -i)) res += this->bit[i];
    return res;
  }
} typedef Fenwick;

int main() {
  freopen("Fenwick.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; scanf("%d", &n);

  vector<int>A;
  for (int i = 1; i <= n; ++i) {
    int u; scanf("%d", &u); A.push_back(u);
  }

  Fenwick fenwickTree(A);

  // Init BIT
  int q; scanf("%d", &q);
  while (q--) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    if (u == 1) fenwickTree.update(v, w);
    else {
      int left = fenwickTree.query(v - 1);
      int right = fenwickTree.query(w);

      printf("Sum of all elements in range [%d, %d] = %d\n", v, w, right - left);
    }
  }

  return 0;
}
