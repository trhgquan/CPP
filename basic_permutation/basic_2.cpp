#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// calculate total items with factorial.
int factorial (int slen)
{
    if (slen > 1)
        return slen * factorial(slen - 1);
    return 1;
}

void permutation(string s) {
    // keep in mind that in order to get all permutations your initial string/array must be sorted in ascending order
    std::sort(s.begin(), s.end());
    // this is the brute-force permutation way.
    int i = 1;
    std::cout << "Total values after permutation: " <<  factorial(s.length()) << '\n';
    do {
        std::cout << s << " - " << i << '\n';
        i++;
    } while (std::next_permutation(s.begin(), s.end()));
}

int main() {
    string s;

    std::cout << "Type some lorem ipsum:" << '\n';
    std::cin >> s;

    // we need to have an input value.
    if (s.length() <= 2)
        s = "Lorem";

    permutation(s);

    return 0;
}
