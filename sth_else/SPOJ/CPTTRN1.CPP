/*
* This does not need I/O files.
*/
#include <stdio.h>

int T; // Number of testcases
int L, C; // L for lines, C for columns

void Solve() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &C);
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (i % 2 == 0 && j % 2 != 0)
                    printf("%s", ".");
                else if (i % 2 != 0 && j % 2 == 0)
                    printf("%s", ".");
                else printf("%s", "*");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    Solve();
    return 0;
}
