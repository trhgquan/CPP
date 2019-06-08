#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SEARCH.INP", ios::in);
ofstream bfile("SEQUENTIAL.OUT", ios::out);

int N, K;
int A[1001];
bool found;

void Read() {
    afile >> N >> K;
    for (int i = 1; i <= N; ++i)
        afile >> A[i];
    afile.close();
}

void Sequential_search() {
    found = false;

    for (int i = 1; i <= N; ++i)
        if (A[i] == K) {
            bfile << "Element found!";
            return;
        }
    bfile << "Element not exist!";
}

void Write() {
    bfile.close();
}

int main() {
    Read();
    Sequential_search();
    Write();
    return 0;
}
