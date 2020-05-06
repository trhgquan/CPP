// Given number a (a very-big number). Return the factorial of a, modulo 10^9 + 7.
// That would be *a! mod 10^9*

#include <iostream>

using namespace std;

const unsigned M = 1000000007;
int n;

/**
 * Simple factorial function
 * @param  a int
 * @return   unsigned long long
 */
unsigned long long factorial(int a) {
    unsigned long long f = 1;

    // So the solution here is find every single calculation and modulo that calculation M.
    // Example: 3! % m = ( ( ( ( 1 % M ) * 2 ) % M ) * 3 ) % M

    for (int i = 1; i <= a; ++i)
        f = (f * i) % M;

    return f;
}

int main(int argc, char const *argv[]) {
    cin >> n;
    cout << factorial(n);
    return 0;
}
