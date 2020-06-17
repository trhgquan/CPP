/**
 * Given a knight's starting position, print a path,
 * that the knight travels throughout 8 * 8 = 64 cells of the chessboard.
 *
 * Note that sometimes this program cannot provide answer,
 * due to Schwenk's proof.
 * https://en.wikipedia.org/wiki/Knight%27s_tour#Existence
 *
 * (Backtracking approach).
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

#define NMAX 8

int chessboard[NMAX][NMAX];
int count = 0;
int stop = 0;

/**
 * This function print the chessboard to screen.
 */
void printChessboard() {
    printf("Here's a result:\n");
    for (int i = 0; i < NMAX; ++i){
        for (int j = 0; j < NMAX; ++j)
            printf("%d\t", chessboard[i][j]);
        printf("\n");
    }
}

/**
 * This function try to place the knight at (x, y).
 * @param x x-pos
 * @param y y-pos
 */
void Try(int x, int y) {
    // If this cell is already visited, don't visit it.
    if (chessboard[x][y]) return;

    // Increse number of cells visited,
    // and mark this cell as visited.
    ++count;
    chessboard[x][y] = count;

    // If we reach the final cell.
    if (count == NMAX * NMAX) {
        // Print the chessboard.
        printChessboard();

        // Exit with SUCCESS code.
        exit(0);
    }

    // Check for nearby-valid cells.
    if (x - 2 >= 0 && y - 1 >= 0)
        Try(x - 2, y - 1);
    if (x - 2 >= 0 && y + 1 < NMAX)
        Try(x - 2, y + 1);
    if (x - 1 >= 0 && y - 2 >= 0)
        Try(x - 1, y - 2);
    if (x - 1 >= 0 && y + 2 < NMAX)
        Try(x - 1, y + 2);
    if (x + 1 < NMAX && y - 2 >= 0)
        Try(x + 1, y - 2);
    if (x + 1 < NMAX && y + 2 < NMAX)
        Try(x + 1, y + 2);
    if (x + 2 < NMAX && y - 1 >= 0)
        Try(x + 2, y - 1);
    if (x + 2 < NMAX && y + 1 < NMAX)
        Try(x + 2, y + 1);

    // Reverse: mark this cell as unvisited
    --count;
    chessboard[x][y] = 0;
}

/**
 * This function initialise the chessboard.
 */
void Init() {
    for (int i = 0; i < NMAX; ++i)
        for (int j = 0; j < NMAX; ++j)
            chessboard[i][j] = 0;
}

int main() {
    // initialise the chessboard.
    Init();

    // get starting position.
    printf("Start position (x, y). Notice that this chessboard position start from 0: ");
    int start_x, start_y; scanf("%d%d", &start_x, &start_y);
    printf("Not always these solutions give result, some other solutions need times to calculate.\n");

    // backtracking to create a solution.
    Try(start_x, start_y);

    return 0;
}
