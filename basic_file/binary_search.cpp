#include "iostream"
#include "fstream"

using namespace std;

int main() {
    std::ifstream afile("binary_search.inp", std::ios::in);
    std::ofstream bfile("binary_search.out", std::ios::out);

    int length, keyword;
    afile >> length >> keyword;

    int count = 0, numbers[length];

    while (count < length && afile >> numbers[count]) {
        count++;
    }

    int min = 0, max = count - 1, mid;
    bool found = false;

    while (numbers[min] <= keyword && numbers[max] >= keyword && !found) {
        if (numbers[min] == keyword || numbers[max] == keyword)
            found = true;
        else {
            mid = (min + max) / 2;
            if (numbers[mid] == keyword)
                found = true;
            else if (numbers[mid] > keyword)
                max = mid - 1;
            else if (numbers[mid] < keyword)
                min = mid + 1;
        }
    }

    bfile << ((found) ? "found" : "not found");

    afile.close();
    bfile.close();

    return 0;
}
