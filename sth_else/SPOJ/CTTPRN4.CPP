#include <stdio.h>

int T, L, C, h, w;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &L, &C, &h, &w);
        for (int i = 1; i <= (h + 2) * L - (L - 1); ++i){
            for (int j = 1; j <= (w + 2) * C - (C - 1); ++j)
                if (i == 1 ||
                    j == 1 ||
                    i == (h + 2) * L - (L - 1) ||
                    j == (w + 2) * C - (C - 1) ||
                    (i - 1) % (h + 1) == 0 ||
                    (j - 1) % (w + 1) == 0)
                    printf("*");
                else printf(".");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
