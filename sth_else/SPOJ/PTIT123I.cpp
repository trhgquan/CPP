/**
 * PTIT123I - https://www.spoj.com/PTIT/problems/PTIT123I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
#include<vector>
#define NMAX 300001
using namespace std;

int main() {
    // Initialise a Sieve of Eratosthenes
    vector<int>P(NMAX, 1), C(NMAX, 0);
    P[0] = 0; P[1] = 0;
    for (int i = 2; i < NMAX; ++i)
        for (int j = 2; j * i < NMAX; ++j) P[i * j] = 0;
    // Do some dynamic counting tricks.
    for (int i = 2; i < NMAX; ++i){
        if (P[i]) C[i] = C[i - 1] + 1;
        else C[i] = C[i - 1];
    }

    // This process the problem's request.
    while (1) {
        int N; scanf("%d", &N);
        if (N == 0) break;

        printf("%d\n", C[2 * N] - C[N]);
    }
    return 0;
}
