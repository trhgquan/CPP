#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ifstream afile("short.inp", std::ios::in);
    std::ofstream bfile("short.out", std::ios::out);

    int length, count, i, temp;
    bool check = true;

    afile >> length;
    count = 0;

    int numbers[length];

    while (count < length && afile >> numbers[count]) {
        count++;
    }

    while (check) {
        check = false;
        for (i = 0; i < length - 1; i++) {
            if (numbers[i] > numbers[i+1]) {
                temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                check = true;
            }
        }
    }


    count = 0;

    while (count < length && bfile << numbers[count] << ' ') {
        count++;
    }

    afile.close();
    bfile.close();

    return 0;
}
