/**
 * P147PROH - https://www.spoj.com/PTIT/problems/P147PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int order = 0;
    while (1) {
        char S1[1001], S2[1001];
        scanf("%s%s", S1, S2);

        // Testcases end
        if (strcmp(S1, "END") == 0 && strcmp(S2, "END") == 0)
            break;

        printf("Case %d: ", ++order);

        if (strlen(S1) != strlen(S2)) printf("different\n");
        else {
            int countS1[27] = {0}, countS2[27] = {0};
            for (unsigned i = 0; i < strlen(S1); ++i) {
                ++countS1[S1[i] - 'a'];
                ++countS2[S2[i] - 'a'];
            }

            int same = 1;
            for (unsigned i = 0; i < 26; ++i)
                if (countS1[i] != countS2[i]) {same = 0; break;}

            if (same) printf("same\n");
            else printf("different\n");
        }


    }
    return 0;
}
