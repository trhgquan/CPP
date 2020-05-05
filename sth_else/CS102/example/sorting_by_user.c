/**
 * This is an example for
 * - pointer_and_memory_allocation/dimensional_allocation_1.c
 * - pointer_and_memory_allocation/pointer_and_function.c
 *
 * Code by @trhgquan - https://github.com/trhgquan
 * Example for CS102 only.
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * This swap two variable, using pointer
 * @param a pointer to first variable
 * @param b pointer to second variable
 */
void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * This using for ascending sort, aka sort the array to non-decreasing array.
 * @param a pointer to first variable
 * @param b pointer to second variable
 */
void ascending(int* a, int* b) {
    if (*a > *b) swap(a, b);
}

/**
 * This using for descending sort, aka sort the array to non-increasing array
 * @param a pointer to first variable
 * @param b pointer to second variable
 */
void descending(int* a, int* b) {
    if (*a < *b) swap(a, b);
}

/**
 * Define a sort type, which compare two variable a and b.
 */
typedef void (*sort_type)(int* a, int* b);

/**
 * Bubble sort
 * @param array   pointer to an array
 * @param size    that array's size
 * @param compare compare function
 */
void sortByType(int* array, int size, sort_type compare) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size; ++j)
            compare(&array[i], &array[j]);
}

int main() {
    // Get array size.
    printf("Number of elements: ");
    int N; scanf("%d", &N);

    // Create a dynamic-memory-allocation array.
    int* array = (int*)malloc(N);

    // Get the value.
    for (int i = 0; i < N; ++i) scanf("%d", &array[i]);

    // Sort ascending, then print the array
    printf("Array sorted (ascending): ");
    sortByType(array, N, ascending);
    for (int i = 0; i < N; ++i) printf("%d ", array[i]);

    // a small line break
    printf("\n");

    // Sort descending, then print the array
    // of course, I'll not print the previous sorted array backward.
    printf("Array sorted (descending): ");
    sortByType(array, N, descending);
    for (int i = 0; i < N; ++i) printf("%d ", array[i]);

    // Release the array
    free(array);

    // This can go further: we can create an array without knowing
    // how many elements will it get. But I'll leave this in a corner.

    return 0;
}
