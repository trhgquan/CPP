#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// permutation from stackoverflow. can\'t get it anyways.
void permutation (int k, string &str)
{
    for (int i = 1; i < str.size(); i++) {
        std::swap(str[k % (i + 1)], str[i]);
        std::cout << str << '\n';
        k = k / (i + 1);
    }
}

// recursive factorial.
int factorial (int k)
{
    if (k > 1)
        return k * factorial (k - 1);
    return 1;
}

int main() {
    // For the string s of length n, for any k from 0 to n! - 1 inclusive, the following modifies s to provide a unique permutation
    string s = "123";
    // To generate all permutations, run it for all n! k values on the original value of s.
    permutation(factorial(s.length()), s);
    return 0;
}
