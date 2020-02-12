/**
 * PTIT126E - https://www.spoj.com/PTIT/problems/PTIT126E
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    while (1) {
        char s[71]; scanf("%s", s);
        // printf("%s ", s);
        if (s[0] == '#') break;

        unsigned count_yes = 0;
        unsigned count_no = 0;
        unsigned count_abs = 0;
        unsigned count_not = 0;

        for (unsigned i = 1; i <= strlen(s); ++i){
            if (s[i - 1] == 'A') ++count_abs;
            if (s[i - 1] == 'Y') ++count_yes;
            if (s[i - 1] == 'N') ++count_no;
            if (s[i - 1] == 'P') ++count_not;
        }

        // printf("yes %d no %d absent %d ", count_yes, count_no, count_abs);
        if (count_abs < count_yes + count_no + count_not) {
            if (count_yes > count_no) printf("yes\n");
            else if (count_yes < count_no) printf("no\n");
            else printf("tie\n");
        } else printf("need quorum\n");
    }
    return 0;
}
