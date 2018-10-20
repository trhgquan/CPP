#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ifstream afile("short.inp", std::ios::in);
    std::ofstream bfile("short.out", std::ios::out);

    int length, i, temp;
    bool check = true;

    afile >> length;

    int numbers[length];
    int count = 0;

    while (count < length && afile >> numbers[count])
        count++;

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

    while (count < length && bfile << numbers[count] << '\t')
        count++;

    afile.close();
    bfile.close();

    return 0;
}
