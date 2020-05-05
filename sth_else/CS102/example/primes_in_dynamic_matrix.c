/**
 * This program let user input a 2-d integer matrix,
 * and output all primes in it.
 *
 * Resources used:
 * - pointer_and_memory_allocation/dimensional_allocation_1.c
 * - pointer_and_memory_allocation/dimensional_allocation_2.c
 *
 * Code by @trhgquan - https://github.com/trhgquan
 * CS102 Practice only.
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/**
 * This function check if a number is prime.
 * (Recommend using Sieve of Eratosthenes for bigger tests).
 *
 * @param  a number to check if it is a prime or not.
 * @return 1 if the number is a prime, 0 otherwise.
 */
int isPrime(int a) {
    if (a < 2) return 0;
    if (a == 2) return 1;

    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;

    return 1;
}

int main() {
    // Get matrix's size.
    int R, C;
    printf("Number of rows: "); scanf("%d", &R);
    printf("Number of columns: "); scanf("%d", &C);
    printf("Start typing %d items, separate by spaces or endline.\n", R * C);

    // Create a 2-d dynamic allocation array.
    int** matrix = (int**)malloc(R);

    // Get the matrix's elements.
    for (int i = 0; i < R; ++i) {
        matrix[i] = (int*)malloc(sizeof(R) * C);
        for (int j = 0; j < C; ++j) scanf("%d", &matrix[i][j]);

        // As CP's way, I should count number of primes here,
        // but this is a practice anw, so counting will be separate
        // to another code block.
    }

    // Create a 1-d array to store primes.
    int* primes = (int*)malloc(sizeof(int));
    // Index.
    int primeIndex = 0;

    // Search for primes in matrix
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (isPrime(matrix[i][j])) {
                // We got a prime! Insert it into the primes array,
                primes[primeIndex] = matrix[i][j];
                // Increase the index.
                ++primeIndex;
            }

    // Print the matrix.
    printf("Input matrix:\n");
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Print primes in the matrix.
    printf("Primes in the matrix (%d): ", primeIndex);
    for (int i = 0; i < primeIndex; ++i) printf("%d ", primes[i]);

    // Release the matrix
    for (int i = 0; i < R; ++i) free(matrix[i]);
    free(matrix);
    free(primes);

    return 0;
}
