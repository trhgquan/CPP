#include <stdio.h>

int T, L, C;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &C);
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= C; ++j)
                if (i == 1 ||
                    i == L ||
                    j == 1 ||
                    j == C)
                    printf("%s", "*");
                else printf("%s", ".");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
