#include <stdio.h>

int T, L, C;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &C);
        for (int i = 1; i <= 4 * L - (L - 1); ++i){
            for (int j = 1; j <= 4 * C - (C - 1); ++j)
                if (i == 1 || (i - 1) % 3 == 0 || j == 1 || (j - 1) % 3 == 0)
                    printf("*");
                else printf(".");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
