/**
 * BCLIQ - https://www.spoj.com/PTIT/problems/BCLIQ
 * Code by @trhgquan - https://github.com/trhgquan
 */

 #include <stdio.h>
 #include <limits.h>

 int answer, n, U[1001];
 long A[1001];

 void Read() {
     scanf("%d", &n);
     for (int i = 1; i <= n; ++i)
         scanf("%ld", &A[i]);
     for (int i = 0; i <= n; ++i)
         U[i] = 1;
     U[0] = 0;
     A[0] = LONG_MIN;
 }

 int main() {
     Read();
     answer = 1;
     for (int i = 1; i <= n; ++i) {
         int jmax = 0;
         for (int j = 0; j < i; ++j) {
             if (A[i] > A[j] && U[jmax] < U[j])
                 jmax = j;
         }
         U[i] = U[jmax] + 1;
         if (U[i] > answer) answer = U[i];
     }
     printf("%d", answer);

     return 0;
 }
