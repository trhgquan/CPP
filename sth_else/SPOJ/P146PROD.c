/**
 *  P146PROD - https://www.spoj.com/PTIT/problems/P146PROD
 *  Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
  int n; scanf("%d", &n);

  int count = 0;
  for (int i = 1; i <= n; ++i){
    int can_solve = 0;
    for (int j = 1; j <= 3; ++j) {
      int u; scanf("%d", &u);
      if (u == 1) ++can_solve;
    }

    if (can_solve >= 2) ++count;
  }

  printf("%d\n", count);
  return 0;
}
