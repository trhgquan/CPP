/**
 * BCPENNY - https://www.spoj.com/PTIT/problems/BCPENNY
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        char S[51]; scanf("%s", S);
        int coins[10] = {0};
        for (unsigned i = 0; i < 38; ++i) {
            if (S[i] == 'T' && S[i + 1] == 'T' && S[i + 2] == 'T')
                ++coins[1];
            if (S[i] == 'T' && S[i + 1] == 'T' && S[i + 2] == 'H')
                ++coins[2];
            if (S[i] == 'T' && S[i + 1] == 'H' && S[i + 2] == 'T')
                ++coins[3];
            if (S[i] == 'T' && S[i + 1] == 'H' && S[i + 2] == 'H')
                ++coins[4];
            if (S[i] == 'H' && S[i + 1] == 'T' && S[i + 2] == 'T')
                ++coins[5];
            if (S[i] == 'H' && S[i + 1] == 'T' && S[i + 2] == 'H')
                ++coins[6];
            if (S[i] == 'H' && S[i + 1] == 'H' && S[i + 2] == 'T')
                ++coins[7];
            if (S[i] == 'H' && S[i + 1] == 'H' && S[i + 2] == 'H')
                ++coins[8];
        }

        printf("%d ", N);
        for (int i = 1; i <= 8; ++i) printf("%d ", coins[i]);
        printf("\n");
    }
    return 0;
}
