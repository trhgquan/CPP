#include <string.h>
#include <iostream>

#define NMAX 10000

using namespace std;

int PRIME[NMAX], input;

/**
 * generate an array, which contains prime number from 2 to NMAX
 */

int main () {
    cout << "LIMIT OF THE PRIMES: " << '\n';
    cin >> input;

    memset(PRIME, -1, NMAX);

    for (int i = 2; i <= input; i++)
        if (PRIME[i]) {
            int num = i;
            for (int j = 2; num*j <= input; j++)
                PRIME[num*j] = 0;
            cout << num << '\n';
        }

    return 0;
}
