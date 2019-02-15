/**
 * https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
 * IN A NUTSHELL: Find the largest rectangle
 */
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream afile("LARGEST_RECTANGLE.inp", ios::in);
ofstream bfile("LARGEST_RECTANGLE.out", ios::out);

int R, C;
int i_Graph[101][101];

void read() {
    afile >> R >> C;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            afile >> i_Graph[i][j];
}

int maxHist (int row[]) {
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;

    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i]) {
            result.push(i++);
        } else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);

            max_area = max(area, max_area);
        }
    }

    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }

    return max_area;

}

int maxRectangle (int A[][101]) {

    int result = maxHist(A[0]);

    for (int i = 1; i < R; ++i) {

        for (int j = 0; j < C; ++j)
            if (A[i][j])
                A[i][j] += A[i - 1][j];

        result = max(result, maxHist(A[i]));

    }

    return result;

}


int main() {

    read();

    bfile << "Maximum rectangle size: " << maxRectangle(i_Graph) << endl;

    afile.close();
    bfile.close();

    return 0;

}
