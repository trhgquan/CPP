/**
 * P172PROH - https://www.spoj.com/PTIT/problems/P172PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char S[101]; scanf("%s", S);
    int count = 0;
    for (unsigned i = 0; i < strlen(S); ++i) {
        if (S[i] == 'c' && (S[i + 1] == '=' || S[i + 1] == '-')){
            // printf("c= or c- found\n");
            ++i; ++count;
        }
        else if (S[i] == 'd' && S[i + 1] == '-'){
            // printf("d- found\n");
            ++i; ++count;
        }
        else if (S[i] == 'd' && S[i + 1] == 'z' && S[i + 2] == '=') {
            // printf("dz= found\n");
            i += 2; ++count;
        }
        else if ((S[i] == 'n' && S[i + 1] == 'j') ||
                (S[i] == 'l' && S[i + 1] == 'j')){
            // printf("nj or lj found\n");
            ++i; ++count;
        }
        else if ((S[i] == 's' && S[i + 1] == '=') ||
                (S[i] == 'z' && S[i + 1] == '=')){
            // printf("s= or z= found\n");
            ++i; ++count;
        }
        else {
            // printf("normal char %c found\n", S[i]);
            ++count;
        }
    }
    printf("%d", count);
    return 0;
}
