/**
 * ABCPATH - https://www.spoj.com/problems/ABCPATH
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<fstream>
using namespace std;

ifstream afile("ABCPATH.inp", ios::in);
ofstream bfile("ABCPATH.out", ios::out);

int H, W;
char G[101][101];
bool V[101][101];
int best, record;

void Read() {
    afile >> H >> W;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j) {
            afile >> G[i][j];
            V[i][j] = false;
        }
}

void Try(int u, int v, int next) {
    V[u][v] = true;
    if (next > record) record = next;
    if (G[u + 1][v] == G[u][v] + 1 && u + 1 <= H && !V[u + 1][v]) Try(u + 1, v, next + 1);
    if (G[u][v + 1] == G[u][v] + 1 && v + 1 <= W && !V[u][v + 1]) Try(u, v + 1, next + 1);
    if (G[u - 1][v] == G[u][v] + 1 && u - 1 > 0 && !V[u - 1][v]) Try(u - 1, v, next + 1);
    if (G[u][v - 1] == G[u][v] + 1 && v - 1 > 0 && !V[u][v - 1]) Try(u, v - 1, next + 1);
    if (G[u + 1][v + 1] == G[u][v] + 1 && u + 1 <= H && v + 1 <= W && !V[u + 1][v + 1]) Try(u + 1, v + 1, next + 1);
    if (G[u - 1][v - 1] == G[u][v] + 1 && u - 1 > 0 && v - 1 > 0 && !V[u - 1][v - 1]) Try(u - 1, v - 1, next + 1);
    if (G[u + 1][v - 1] == G[u][v] + 1 && u + 1 <= H && v - 1 > 0 && !V[u + 1][v - 1]) Try(u + 1, v - 1, next + 1);
    if (G[u - 1][v + 1] == G[u][v] + 1 && u - 1 > 0 && v + 1 <= W && !V[u - 1][v + 1]) Try(u - 1, v + 1, next + 1);
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int count = 0;
    while (true) {
        Read();
        record = 0, best = 0;
        if (H == 0 && W == 0) break;
        count++;
        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j)
                if (G[i][j] == 65 && !V[i][j]) {
                    Try(i, j, 1);
                    if (record > best) best = record;
                    record = 0;
                }
        bfile << "Case " << count << ": " << best << endl;
        best = 0;
    }
    afile.close(); bfile.close();
    return 0;
}
