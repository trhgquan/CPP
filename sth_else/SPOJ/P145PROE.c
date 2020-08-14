/**
 * P145PROE - https://www.spoj.com/PTIT/problems/P145PROE
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char s[20]; scanf("%s", s); int nMax = strlen(s) * 5 - strlen(s) + 1;

    // Declare and initialise the result matrix
    char graph[5][nMax];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < nMax; ++j)
            graph[i][j] = '.';

    // Draw cells
    int xStart = 2; int yStart = 2; int count = 0;
    for (unsigned i = 0; i < strlen(s); ++i) {
        ++count;
        graph[xStart][yStart] = s[i];
        if (count == 3) {
            graph[xStart + 1][yStart + 1] = '*';
            graph[xStart - 1][yStart - 1] = '*';
            graph[xStart + 1][yStart - 1] = '*';
            graph[xStart - 1][yStart + 1] = '*';
            graph[xStart + 2][yStart] = '*';
            graph[xStart - 2][yStart] = '*';
            graph[xStart][yStart + 2] = '*';
            graph[xStart][yStart - 2] = '*';
        } else {
            graph[xStart - 1][yStart - 1] = '#';
            graph[xStart + 1][yStart + 1] = '#';
            graph[xStart + 1][yStart - 1] = '#';
            graph[xStart - 1][yStart + 1] = '#';
            graph[xStart + 2][yStart] = '#';
            graph[xStart - 2][yStart] = '#';
            graph[xStart][yStart + 2] = '#';
            if (graph[xStart][yStart - 2] == '.')
                graph[xStart][yStart - 2] = '#';
        }
        yStart += 4;

        if (count == 3) count = 0;
    }

    // Print the result
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < nMax; ++j)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
