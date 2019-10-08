/**
  * KADANE'S ALGORITHM TO FIND THE CONTIGUOUS SUBARRAY WHICH SUM IS LARGEST.
  * in a nutshell: declare 2 variables, 1 for current and 1 is answer.
  * check from the 1st item, current = max(item, current + item)
  * Source: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
  **/
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    long A[100001];
    long n;

    scanf("%ld", &n);
    for (long i = 1; i <= n; ++i)
        scanf("%ld", &A[i]);

    /**
     * Kadane's algorithm start from here.
     * Note: this can handle an array with all elements is negative.
     */
    long max_ending_here = A[1];
    long max_ending_sofar = A[1];

    for (long i = 2; i <= n; ++i){
        max_ending_here = max(A[i], max_ending_here + A[i]);
        max_ending_sofar = max(max_ending_here, max_ending_sofar);
    }

    printf("%ld", max_ending_sofar);
    return 0;
}
