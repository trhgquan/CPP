/**
 * PEBBLE - https://www.spoj.com/problems/PEBBLE
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
#include<string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    int index = 0;
    while (cin >> s) {
        index++;
        int count = 0;
        for (char i: s)
            if ((count % 2 == 0 && i == '1') || (count % 2 != 0 && i == '0')) count++;
        cout << "Game #" << index << ": " << count << endl;
    }
    return 0;
}
