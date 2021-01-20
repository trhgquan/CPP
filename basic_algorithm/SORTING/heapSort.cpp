/**
 * Heap Sort implementation, replace the old ways in DSAP Textbook.
 * Fall 2020, updated 01/20/2021.
 *
 * Code by @trhgquan - https://github.com/trhgquan.
 */
#include<iostream>
using namespace std;

/**
 * Adjust nodes in a heap.
 * @param a    array to sort.
 * @param root root node.
 * @param n    size of the array.
 */
template<class T>
void adjust(T* a, int root, int n) {
  T biggest  = root;
  T leftNode = 2 * root + 1;
  T rightNode = 2 * root + 2;

  if (leftNode < n && a[leftNode] > a[biggest]) biggest = leftNode;
  if (rightNode < n && a[rightNode] > a[biggest]) biggest = rightNode;

  if (biggest != root) {
    swap(a[root], a[biggest]);
    adjust(a, biggest, n);
  }
}

/**
 * heapSort.
 * @param a array to sort.
 * @param n size of array.
 */
template<class T>
void heapSort(T*& a, int n) {
  for (int i = n / 2 - 1; i >= 0; --i) adjust(a, i, n);
  for (int i = n - 1; i > 0; --i) {
    swap(a[0], a[i]);
    adjust(a, 0, i);
  }
}

int main() {
  freopen("SORT.INP", "r+", stdin);
  freopen("HEAP.OUT", "w+", stdout);

  // input
  int n; cin >> n;
  int* a = new int[n + 1];
  for (int i = 0; i < n; ++i) cin >> a[i];

  // sort.
  heapSort(a, n);

  // print the array
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';

  // free pointers.
  delete[] a;
  return 0;
}
