#include <bits/stdc++.h> // For INT_MAX
#include <fstream>

std::ifstream afile("SALESMAN.INP", std::ios::in);
std::ofstream bfile("SALESMAN.OUT", std::ios::out);

int N, M;
int C[101][101];
int T[101], X[101];
int bestWay[101];
bool visited[101];

int minSpending = INT_MAX;

void read() {
    int u, v, t;

    afile >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j)
                C[i][j] = 0;
            else C[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= M; ++i)
    {
        afile >> u >> v >> t;
        C[u][v] = t;
        C[v][u] = t;
    }

    // We start from 1, so 1 is visited
    visited[1] = true;
    for (int i = 2; i <= N; ++i)
        visited[i] = false;

    // Starting from 1
    X[1] = 1;
    // From 1 to 1 = 0$
    T[1] = 0;
}

void write() {
    // If minSpending = MAX, then no routes exist.
    if (minSpending == INT_MAX)
        bfile << -1 << std::endl;
    else {
        for (int i = 1; i <= N; ++i) {
            if (bestWay[i] != 0)
                bfile << bestWay[i] << " -> ";
        }

        bfile << 1 << std::endl;
        bfile << "Total cost: " << minSpending;
    }
}

void Try (int i) {
    for (int j = 2 ; j <= N; ++j)
        if (!visited[j]) {
            X[i] = j;
            // Calculate the cost at j.
            T[i] = T[i - 1] + C[X[i - 1]][j];

            if (T[i] < minSpending) {
                visited[j] = true;
                if (i == N) {
                    // Check if this is the minimum route.
                    // At this point (i = N), we travelled back to where we started
                    // so we must check if this is the minimum spending by
                    // adding the route last path to the total path cost.
                    if ((T[N] + C[X[N]][1]) < minSpending) {
                        for (int i = 1; i <= N; ++i)
                            bestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }

                } else Try(i + 1);

                visited[j] = false;
            }
        }
}

int main() {
    read();

    Try(2); // Start from 1, then next is 2.

    write();


    afile.close();
    bfile.close();
    return 0;
}
