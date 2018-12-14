// BASICALLY, THIS PROGRAM WILL COUNT
// HOW MANY RECTANGLES CAN BE CREATED
// FROM N 1X1 SQUARE.

#include <stdio.h>
#include <math.h>

int solve(int n);

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        count = count + solve(i);
    printf("%d", count);
    return 0;
}

int solve (int n) {
    int factors = 1;
    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
        if (n % i == 0)
            ++factors;

    return factors;
}
