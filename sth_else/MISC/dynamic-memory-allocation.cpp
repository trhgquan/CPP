/**
 * This program create a unknown-length array,
 * insert values to it and sort it (in a basically easiest way)
 * Notice that I don't declare any arrays as array[max_items].
 * The memory is dynamically allocated.
 */

#include <stdio.h>
#include <malloc.h>
// or,
// #include <stdlib.h>

int array_length;

void Swap(int* a, int* b);
void interchangeSort(int* array);
void printArray(int* array);

int main(int argc, char const *argv[]) {
    // Create a dinamic memory allocation array.
    int *array = (int*)malloc(sizeof(int));

    // Give it some values:
    int i = 0;
    while (true) {
        int x;
        printf("Item no. %d: ", i + 1); scanf("%d", &x);

        if (x >= 0) array[i] = x;
        else break;

        i++;
    }

    // Set the array length
    array_length = i;

    // First, we print the array
    printArray(array);

    // Then, we sort the array
    interchangeSort(array);

    // Finally, print the result so the user can know the array is sorted,
    printArray(array);
    return 0;
}

/**
 * This swap 2 variables value
 * (Using C pointer.)
 */
void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * This sort the array, using a simple sorting method/
 * Google: Interchange Sort
 */
void interchangeSort(int* array) {
    for (int i = 0; i < array_length - 1; ++i)
        for (int j = i; j < array_length; ++j)
            if (array[i] > array[j]) Swap(&array[i], &array[j]);
}

/**
 * This, print the array.
 */
void printArray(int* array) {
    for (int i = 0; i < array_length; ++i)
        printf("%d ", array[i]);
    printf("\nArray length: %d\n", array_length);
}
