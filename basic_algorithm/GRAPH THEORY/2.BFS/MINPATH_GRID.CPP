// A CLASSICAL BFS PROBLEM:
// FIND THE MINIMUM PATH BETWEEN 2 CELLS OF A 2X2 GRID
// WITH THE # IS THE OBSTACLES / BORDER.
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream afile("MINPATH_GRID.INP", ios::in);
ofstream bfile("MINPATH_GRID.OUT", ios::out);

int N, M;
char graph[101][101];
bool visited[101][101];
struct cell {int x; int y; int distance;};
cell A, B;
queue<cell> q;

void Read();
void Write();

int BFS() {
    q.push(A);
    visited[A.x][A.y] = true;

    while (!q.empty()) {
        cell u = q.front(); cell v;
        q.pop();

        if (graph[u.x][u.y] == 'B')
            return u.distance;

        if (graph[u.x + 1][u.y] != '#' && !visited[u.x + 1][u.y]) {
            v.x = u.x + 1; v.y = u.y; v.distance = u.distance + 1;
            q.push(v);
            visited[u.x][u.y] = true;
        }

        if (graph[u.x - 1][u.y] != '#' && !visited[u.x - 1][u.y]) {
            v.x = u.x - 1; v.y = u.y; v.distance = u.distance + 1;
            q.push(v);
            visited[u.x][u.y] = true;
        }

        if (graph[u.x][u.y + 1] != '#' && !visited[u.x][u.y + 1]) {
            v.x = u.x; v.y = u.y + 1; v.distance = u.distance + 1;
            q.push(v);
            visited[u.x][u.y] = true;
        }

        if (graph[u.x][u.y - 1] != '#' && !visited[u.x][u.y - 1]) {
            v.x = u.x; v.y = u.y - 1; v.distance = u.distance + 1;
            q.push(v);
            visited[u.x][u.y] = true;
        }
    }
    return -1;
}

int main() {
    Read();
    Write();
    return 0;
}

void Read() {
    afile >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            afile >> graph[i][j];

            if (graph[i][j] == '#')
                visited[i][j] = true;
            else visited[i][j] = false;

            if (graph[i][j] == 'A') { A.x = i; A.y = j; A.distance = 0; }
            if (graph[i][j] == 'B') { B.x = i; B.y = j; B.distance = 0; }
        }
    afile.close();
}

void Write() {
    bfile << "Position start: (" << A.x << ", " << A.y << ")" << endl;
    bfile << "Position finish: (" << B.x << ", " << B.y <<")" << endl;
    bfile << "Minimum path: " << BFS() << endl;

    bfile.close();
}
