#include <stdio.h>
#include <math.h>

#define lli long long int
#define NMAX 1000002

lli a[NMAX], n;
int c;

lli sqr (lli a) { return a*a; }

void init () {
    for (lli i = 0; i < NMAX; i++)
        a[i] = sqr(i);
}

int main() {
    scanf("%d", &c);
    init();

    while (c--) {
        lli x;

        scanf("%I64d", &n);
        int i = 0, j = sqrt(n);

        while (i <= j) {
            x = a[i] + a[j];
            if (x == n)
                break;
            if (x < n)
                i++;
            else j--;
        }

        if (i <= j)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
