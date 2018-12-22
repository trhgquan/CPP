#include <stdio.h>
#include <string.h>

int t, n;
bool PRIME[1001];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        memset(PRIME, true, sizeof(PRIME));

        for (int i = 2; i <= n; i++)
            if (PRIME[i]) {
                int num = i;
                for (int j = 2; num*j <= n; j++)
                    PRIME[num*j] = false;
            }

        for (int i = 1; i <= n; i++)
            if (PRIME[i])
                printf("%d\n", i);
        printf("\n");
    }
    return 0;
}
