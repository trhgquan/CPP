#include <iostream>
// #include <fstream>
#include <vector>

#define MAX 10001

using namespace std;

ifstream afile("LASTSHOT.inp", ios::in);
ofstream bfile("LASTSHOT.out", ios::out);

int a, b, n, m;
int counter, result;
vector<int> graph[MAX];
int visit[MAX];

void DFS (int u) {
    visit[u] = 1;
    counter++;
    for (int i : graph[u]) {
        if (!visit[i])
            DFS(i);
    }
}

int main() {
    afile >> n >> m;

    for (int i = 1; i <= m; i++) {
        afile >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            visit[j] = 0;
        counter = 0;
        DFS(i);
        result = ((counter > result) ? counter : result);
    }

    bfile << result;

    afile.close();
    bfile.close();
    return 0;
}
