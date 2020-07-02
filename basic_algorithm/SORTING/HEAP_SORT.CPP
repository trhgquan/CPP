#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("HEAP.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Adjust(int root, int endNode) {
    int c, Key;

    Key = K[root];

    while (root * 2 <= endNode) {
        c = root * 2;

        if (c < endNode && K[c] < K[c + 1]) c++;
        if (K[c] <= Key) break;

        K[root] = K[c]; root = c;
    }

    K[root] = Key;
}

void Heap_sort() {
    for (int r = N / 2; r >= 1; --r) Adjust(r, N);
    for (int i = N; i >= 2; --i) {
        swap(K[1], K[i]);
        Adjust(1, i - 1);
    }
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Heap_sort();
    Print();
    return 0;
}
