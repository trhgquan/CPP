/**
 * Generate combination K-size of a string.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

/**
 * This function try to generate combination size K of a string.
 * @param s     string to generate combination.
 * @param pos   pointer to array stores the character's index.
 * @param i     counting variable.
 * @param k     size of a combination result.
 * @param total pointer to the total result - using like a reference parameter in C++.
 */
void Try(char* s, int* pos, int i, int k, int* total) {
    for (int j = pos[i - 1] + 1; j <= (int)strlen(s) - k + i; ++j) {
        // Push the character's position to array.
        pos[i] = j;

        // Stop if the result's length is K.
        if (i == k) {
            // Count total.
            (*total)++;

            // Print the string.
            for (int l = 1; l <= k; ++l) printf("%c", s[pos[l] - 1]);
            printf("\n");
        } else {
            // Continue trying..
            Try(s, pos, i + 1, k, total);
        }
    }

}

int main() {
    // Get the string and K.
    char s[101];
    printf("String: "); scanf("%s", s);
    int k;
    printf("K: "); scanf("%d", &k);

    // Generate combination.
    int total = 0;
    int pos[101]; pos[0] = 0;
    Try(s, pos, 1, k, &total);

    // Print total permutation.
    printf("Total: %d\n", total);

    return 0;
}
