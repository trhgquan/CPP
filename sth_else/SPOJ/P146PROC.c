/**
 *  P146PROC - https://www.spoj.com/PTIT/problems/P146PROC
 *  Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

// Swap two intergers, using pointer
void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

// Selection Sort
void sort(int* color) {
  for (int i = 1; i < 4; ++i)
    for (int j = i + 1; j <= 4; ++j)
      if (color[i] > color[j]) swap(&color[i], &color[j]);
}

int main() {
  int colors[5] = {0};
  int count = 0;
  for (int i = 1; i <= 4; ++i) scanf("%d", &colors[i]);
  sort(colors);
  for (int i = 1; i < 4; ++i)
    if (colors[i] == colors[i + 1]) ++count;
  printf("%d\n", count);
  return 0;
}
