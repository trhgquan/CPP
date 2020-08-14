/**
 * PTIT123J - https://www.spoj.com/PTIT/problems/PTIT123J
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

bool isClose(char a) {
    return (a == ')' || a == ']');
}

char opposite(char a) {
    if (a == '(') return ')';
    if (a == ')') return '(';
    if (a == '[') return ']';
    if (a == ']') return '[';
    return '0';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        stack<char>stk;
        int len = 0; bool can = true;
        while (true) {
            char c; scanf("%c", &c);

            if (c == '\n') continue;
            if (c == '.') break;
            ++len;

            if (opposite(c) != '0' && can) {
                if (!stk.empty()) {
                    if (isClose(c)) {
                        char top = stk.top();
                        if (opposite(top) == c && !isClose(top)) stk.pop();
                        else can = false;
                    } else stk.push(c);
                } else {
                    if (isClose(c)) can = false;
                    else stk.push(c);
                }
            }
        }

        if (len == 0) break;
        if (can && stk.empty()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
