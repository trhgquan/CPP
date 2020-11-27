/**
 * Binary Insertion Sort
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>

/**
 * Find a location to insert, using binary search.
 *
 * @param a     pointer to array.
 * @param key   key to search.
 * @param left  lower bound.
 * @param right upper bound.
 */
int findLocation(int* a, int key, int left, int right) {
  if (left >= right) return (key > a[left] ? left + 1 : left);

  int mid = (left + right) / 2;

  if (a[mid] == key) return mid + 1;
  if (a[mid] > key) return findLocation(a, key, left, mid - 1);
  return findLocation(a, key, mid + 1, right);
}

/**
 * This function sort data in array a.
 * 
 * @param a pointer to array.
 * @param n array size.
 */
void binaryInsertionSort(int* a, int n) {
  for (int i = 1; i < n; ++i) {
    int j = i - 1;

    int key = a[i];

    int location = findLocation(a, key, 0, j);

    while (j >= location) {
      a[j + 1] = a[j];
      --j;
    }

    a[j + 1] = key;
  }
}

int main() {
  freopen("SORT.INP", "r+", stdin);

  int N; std::cin >> N;
  int* A = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; ++i) std::cin >> A[i];

  binaryInsertionSort(A, N);

  for (int i = 0; i < N; ++i) std::cout << A[i] << ' ';

  free(A);
  return 0;
}