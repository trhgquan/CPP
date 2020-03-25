/**
 * SSAM019A - https://www.spoj.com/PTIT/problems/SSAM019A
 * (Also P173PROH - https://www.spoj.com/PTIT/problems/P173PROH)
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        if (N % 2 != 0) printf("0\n");
        else {
            int res = 1;
            for (int i = 2; i <= sqrt(N); ++i) {
                if (i * i == N && N % i == 0)
                    if (i % 2 == 0) ++res;
                if (i * i != N && N % i == 0) {
                    if (i % 2 == 0) ++res;
                    if ((N / i) % 2 == 0) ++res;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
