#include <iostream>
#include <fstream>
#include <queue>

#define NMAX 10000

using namespace std;

int T, FROM, TO, NUMBER_ARRAY[4];
int MARK[NMAX], PRIME[NMAX];
queue<int> q;

ifstream afile("PPATH.inp", ios::in);
ofstream bfile("PPATH.out", ios::out);

void Eratosthenes () {
    for (int i = 2; i <= 10000; i++)
        if (PRIME[i]) {
            int num = i;
            for (int j = 2; num*j <= NMAX; j++)
                PRIME[num*j] = 0;
        }
}

void number_to_array (int array[], int num) {
    for (int i = 3; i >= 0; i--) {
        array[i] = num % 10;
        num /= 10;
    }
}

int array_to_number (int array[]) {
    int res = 1000 * array[0] + 100 * array[1] + 10 * array[2] + array[3];
    return res;
}

int main () {
    for (int i = 1; i <= NMAX; i++)
        PRIME[i] = -1;
    Eratosthenes();

    afile >> T;

    while (T--) {
        afile >> FROM >> TO;

        for (int i = 1; i <= NMAX; i++)
            MARK[i] = -1;

        q.push(FROM);
        MARK[FROM] = 0;

        while (!q.empty()) {
            FROM = q.front();
            q.pop();

            for (int i = 0; i <= 3; i++) {
                number_to_array(NUMBER_ARRAY, FROM);
                for (int j = 0; j <= 9; j++) {
                    NUMBER_ARRAY[i] = j;
                    int temp = array_to_number(NUMBER_ARRAY);
                    if (PRIME[temp] == -1 && temp > 1000 && MARK[temp] == -1) {
                        MARK[temp] = MARK[FROM] + 1;
                        q.push(temp);
                    }
                }
            }
        }

        if (MARK[TO] == -1)
            bfile << "Impossible";
        else bfile << MARK[TO];
        bfile << '\n';
    }


    afile.close();
    bfile.close();

    return 0;
}
