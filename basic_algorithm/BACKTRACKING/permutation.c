/**
 * Generate permutation K-size of a string.
 *
 * (This is the same as STRINGBCKTRACK.cpp,
 * except this can generate K-size permutation,
 * while STRINGBCKTRACK generates strlen(s)-size permutation,
 * aka permuting the string).
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

/**
 * This function try to generate K-size permutation of a string.
 * @param s       string to permute.
 * @param pos     array to store character's position.
 * @param visited array to flag if a character is visited.
 * @param i       counting variable.
 * @param k       a permutation string's size.
 * @param total   pointer to the total result - using like a reference parameter in C++.
 */
void Try(char* s, int* pos, int* visited, int i, int k, int* total) {
    // If permutation size is reached, print the string.
    if (i == k) {
        // Increase the counting variable.
        (*total)++;

        // Print the result.
        for (int j = 0; j < k; ++j) printf("%c", s[pos[j]]);
        printf("\n");
    } else {
        // Check from start of the string,
        // if any character is not used, then use it and release it.
        for (int j = 0; j < (int)strlen(s); ++j) {
            if (!visited[j]) {
                // Use it.
                visited[j] = 1;
                pos[i] = j;

                // Try next position.
                Try(s, pos, visited, i + 1, k, total);

                // and release it.
                visited[j] = 0;
            }
        }
    }
}

int main() {
    // Get the string and K.
    char s[101];
    printf("String: "); scanf("%s", s);
    int k;
    printf("K: "); scanf("%d", &k);

    // Generate permutation.
    int total = 0;
    int pos[101];
    int visited[101]; for (int i = 0; i < 100; ++i) visited[i] = 0;
    Try(s, pos, visited, 0, k, &total);

    // Print total permutation.
    printf("Total: %d\n", total);

    return 0;
}
