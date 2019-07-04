#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("ALLIZWEL.INP", ios::in);
ofstream bfile("ALLIZWEL.OUT", ios::out);

int T; // T for testcases
int R, C; // R for rows, C for columns
// DFS graph
char graph[1001][1001];
// Destination aka the string you want to reach.
char const *destination = "ALLIZZWELL";
// aka destination.length() if destination is a std::string
int const destination_length = 9;
bool flag; // true aka YES, false aka NO

void DFS(int u, int v, int position) {
    char tmp = graph[u][v];

    // stop when the string ALLIZZWELL is formed.
    if (position == destination_length)
        flag = true;

    // no re-visit this point.
    // but actually we will revisit in another approach
    graph[u][v] = '.';

    if (u < C && graph[u + 1][v] == destination[position + 1])
        DFS(u + 1, v, position + 1);
    if (v < R && graph[u][v + 1] == destination[position + 1])
        DFS(u, v + 1, position + 1);
    if (u > 0 && graph[u - 1][v] == destination[position + 1])
        DFS(u - 1, v, position + 1);
    if (v > 0 && graph[u][v - 1] == destination[position + 1])
        DFS(u, v - 1, position + 1);
    if (u < C && v < R &&
        graph[u + 1][v + 1] == destination[position + 1])
        DFS(u + 1, v + 1, position + 1);
    if (u > 0 && v > 0 &&
        graph[u - 1][v - 1] == destination[position + 1])
        DFS(u - 1, v - 1, position + 1);
    if (u < C && v > 0 &&
        graph[u + 1][v - 1] == destination[position + 1])
        DFS(u + 1, v - 1, position + 1);
    if (u > 0 && v < R &&
        graph[u - 1][v + 1] == destination[position + 1])
        DFS(u - 1, v + 1, position + 1);

    // here, set that element back to beginning
    // so we can visit it in other approach.
    graph[u][v] = tmp;
}

void Solve() {
    afile >> T;

    while (T--) {
        afile >> C >> R;

        for (int i = 0; i < C; ++i)
            for (int j = 0; j < R; ++j)
                afile >> graph[i][j];

        flag = false;

        for (int i = 0; i < C; ++i)
            for (int j = 0; j < R; ++j)
                if (graph[i][j] == destination[0])
                    // Approach from every single destination[0]
                    DFS(i, j, 0);

        if (flag) bfile << "YES\n";
        else bfile << "NO\n";
    }

    afile.close();
    bfile.close();
}

int main() {
    Solve();
    return 0;
}
