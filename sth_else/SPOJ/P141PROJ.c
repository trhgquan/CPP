/**
 * P141PROJ - https://www.spoj.com/PTIT/problems/P141PROJ
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    char G[5][5];
    for (int i = 0; i < 4; ++i) scanf("%s", G[i]);

    int found = 0;
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j < 4; ++j)
            if (G[i - 1][j] == G[i][j - 1] && G[i][j - 1] == G[i - 1][j - 1])
                {found = 1; break;}

    if (found) printf("YES");
    else printf("NO");
    return 0;
}
