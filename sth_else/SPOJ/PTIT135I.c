/**
 * PTIT135I - https://www.spoj.com/PTIT/problems/PTIT135I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char number[1001]; scanf("%s", number);
        int count = 1;
        for (unsigned i = 1; i < strlen(number); ++i){
            if (number[i] == number[i - 1]) ++count;
            else {
                printf("%d%d", count, number[i - 1] - 48);
                count = 1;
            }
        }
        printf("%d%d\n", count, number[strlen(number) - 1] - 48);
    }
    return 0;
}
