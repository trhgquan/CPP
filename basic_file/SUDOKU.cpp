// Simple SUDOKU algorithm - StackOverflow.com
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream afile("SUDOKU.inp", ios::in);
ofstream bfile("SUDOKU.out", ios::out);

int graph[9][9];

bool findUnassignedLocation (int graph[9][9], int &row, int &col);
bool usedInCol (int graph[9][9], int col, int num);
bool usedInRow (int graph[9][9], int row, int num);
bool usedInBox (int graph[9][9], int bRow, int bCol, int num);
bool SudokuSolved (int graph[9][9]);

bool isSafe (int graph[9][9], int row, int col, int num) {
    return !usedInRow(graph, row, num) && !usedInCol(graph, col, num) && !usedInBox(graph, row - row % 3, col - col % 3, num);
}

void read() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            afile >> graph[i][j];
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            bfile << graph[i][j] << '\t';
        bfile << '\n';
    }
}

int main () {
    int T;
    afile >> T;

    while (T--) {
        read();
        if (SudokuSolved(graph))
            print();
        else
            bfile << "No solution\n";
    }
    afile.close();
    bfile.close();
    return 0;
}

/* Find if there is a not-filled box */
bool findUnassignedLocation (int graph[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (graph[row][col] == 0)
                return true;
    return false;
}

/* Check if the graph is solved. */
bool SudokuSolved (int graph[9][9]) {
    int row, col;
    if (!findUnassignedLocation(graph, row, col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(graph, row, col, num)) {
            graph[row][col] = num;
            if (SudokuSolved(graph))
                return true;
            graph[row][col] = 0;
        }
    }
    return false;
}

/* Check if a number is used in a column */
bool usedInCol (int graph[9][9], int col, int num) {
    for (int row = 0; row < 9; row++)
        if (graph[row][col] == num)
            return true;
    return false;
}

/* Check if a number is used in a row */
bool usedInRow (int graph[9][9], int row, int num) {
    for (int col = 0; col < 9; col++)
        if (graph[row][col] == num)
            return true;
    return false;
}

/* Check if a number is used in a box */
bool usedInBox (int graph[9][9], int bRow, int bCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (graph[row + bRow][col + bCol] == num)
                return true;
    return false;
}
