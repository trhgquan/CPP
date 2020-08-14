/**
 * P162SUMA - https://www.spoj.com/PTIT/problems/P162SUMA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
#include<vector>
using namespace std;

struct stick {
    int length;
    int number;
};

void swap(stick *a, stick *b) {
    stick c = *a;
    *a = *b;
    *b = c;
}

int main() {
    vector<stick>S;
    for (int i = 0; i < 6; ++i) {
        int u; scanf("%d", &u);
        int found = 0;
        for (unsigned j = 0; j < S.size(); ++j)
            if (S[j].length == u && S[j].number < 4) {++S[j].number; found = 1; break;}
        if (!found) S.push_back({u, 1});
    }

    for (unsigned i = 0; i < S.size() - 1; ++i)
        for (unsigned j = i + 1; j < S.size(); ++j)
            if (S[i].number > S[j].number) swap(&S[i], &S[j]);

    // for (unsigned i = 0; i < S.size(); ++i) printf("%d %d\n", S[i].length, S[i].number);

    if (S[0].length != S[1].length &&
        S[0].number == S[1].number &&
        S[2].number == 4)
        printf("Bear");
    else if (
        (S[0].length == S[1].length && S[0].number == S[1].number && S[2].number == 4) ||
        (S[0].number == 2 && S[1].number == 4))
        printf("Elephant");
    else printf("Alien");
    return 0;
}
