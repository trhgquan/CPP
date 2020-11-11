/**
 * Sequential Search (aka Linear Search).
 *
 * Code by @trhgquan - https://github.com/trhgquan
 * Re-wrote Nov. 2020.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Classical Linear Search.
 * @param  a pointer to the array to search.
 * @param  n total elements of the array.
 * @param  k key to find.
 * @return   first occur of k's index, -1 if k does not exist.
 */
int linearSearch(int* a, int n, int k) {
  for (int i = 0; i < n; ++i)
    if (a[i] == k) return i;
  return -1;
}

/**
 * Sentinel Linear Search.
 * @param  a pointer to the array to search.
 * @param  n total elements of the array.
 * @param  k key to find.
 * @return   first occur of k's index, -1 if k does not exist.
 */
int sentinelLinearSearch(int* a, int n, int k) {
  int currentLast = a[n - 1]; a[n - 1] = k; int i = 0;

  while (a[i] != k) ++i;

  a[n - 1] = currentLast;

  if (i < n - 1 || a[n - 1] == k) return i;
  return -1;
}

int main() {
  freopen("SEARCH.INP", "r+", stdin);
  freopen("LINEAR.OUT", "w+", stdout);

  int n, k; scanf("%d%d", &n, &k);
  int* a = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  printf("This test will print the first index that k appears, -1 otherwise.\n");
  printf("Normal Linear Search: %d\n", linearSearch(a, n, k));
  printf("Sentinel Linear Search: %d\n", sentinelLinearSearch(a, n, k));

  free(a);
  return 0;
}
