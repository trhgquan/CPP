/**
 * P196PROC - https://www.spoj.com/PTIT/problems/P196PROC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

char win(char a) {
    if (a == 'K') return 'B';
    if (a == 'B') return 'G';
    return 'K';
}

char winOfTwo(char a, char b) {
    if (win(a) == b) return b;
    return a;
}

int main() {
    int N; scanf("%d", &N);
    char robot1[101], robot2[101]; scanf("%s%s", robot1, robot2);
    for (int i = 0; i < N; ++i) {
        if (robot1[i] == robot2[i]) printf("%c", win(robot1[i]));
        else printf("%c", winOfTwo(robot1[i], robot2[i]));
    }
    return 0;
}
