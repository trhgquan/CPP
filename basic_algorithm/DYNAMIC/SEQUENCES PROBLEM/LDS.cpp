/**
 * LONGEST DECREASE SUBSEQUENCES.
 * This using 2 implementations: using DP (DYNAMIC PROGRAMMING) and using Binary Search.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Using Dynamic Programming
 * O(n^2)
 */
int LDS1(vector<int> a) {
    vector<int>b(a.size(), 1);

    int res = 1;
    for (unsigned i = 0; i < a.size(); ++i)
        for (unsigned j = 0; j < i; ++j){
            if (a[j] > a[i] && b[j] + 1 > b[i]) b[i] = b[j] + 1;
            res = max(b[i], res);
        }

    return res;
}

/**
 * Using Binary search
 * O(nlogn)
 */
int LDS2(vector<int> a) {
    vector<int> b(a.size(), INT_MIN);
    int res = 0;
    b[0] = INT_MAX;

    for (unsigned i = 0; i < a.size(); ++i) {
        int mid, low, high;

        low = 0;
        high = res;

        while (low <= high) {
            mid = (low + high) / 2;
            if (b[mid] > a[i])
                low = mid + 1;
            else high = mid - 1;
        }

        b[low] = a[i];
        res = max(low, res);
    }

    return res;
}

int main() {
    vector<int> x = {95, -41, -84, -18, -83};
    cout << LDS1(x) << endl;
    cout << LDS2(x) << endl;
    return 0;
}
