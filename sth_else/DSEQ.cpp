#include <bits/stdc++.h>
#include <fstream>

using namespace std;
// TODO: giai lai bai nay theo huong cua anh chan bo.
#define N 1000100

int n, a[N], cntMax[N], cntMin[N];
long long MAX[N], MIN[N];

int main() {
    ifstream afile("DSEQ.inp", ios::in);
    ofstream bfile("DSEQ.out", ios::out);

    afile >> n;
    for (int i = 0; i<n; i++)
        afile >> a[i];

    long long sum = 0;

    MIN[n] = 1e16;
    MAX[n] = -1e16;

    for (int i = n - 1; i >= 0; i--) {
        sum += 1ll * a[i];
        if (sum < MIN[i + 1]) {
            MIN[i] = sum;
            cntMin[i] = 1;
        }
        else {
            if (sum == MIN[i + 1]) {
                MIN[i] = MIN[i + 1];
                cntMin[i] = cntMin[i + 1] + 1;
            }
            else {
                MIN[i] = MIN[i + 1];
                cntMin[i] = cntMin[i + 1];
            }
        }
        //
        if (sum > MAX[i + 1]) {
            MAX[i] = sum;
            cntMax[i] = 1;
        }
        else {
            if (sum == MAX[i + 1]) {
                MAX[i] = MAX[i + 1];
                cntMax[i] = cntMax[i + 1] + 1;
            }
            else {
                MAX[i] = MAX[i + 1];
                cntMax[i] = cntMax[i + 1];
            }
        }
    }
    long long ans = -1e16;
    long long cnt = 0;
    sum = 0;
    for (int i = 0; i<n - 1; i++) {
        sum += a[i];
        if (sum >= MIN[i + 1]) {
            long long tmp = sum - MIN[i + 1];
            if (tmp == ans) cnt += cntMin[i + 1];
            else {
                if (tmp > ans) {
                    cnt = cntMin[i + 1];
                    ans = tmp;
                }
            }
        }
        if (sum <=MAX[i + 1]) {
            if (sum == MAX[i + 1] && MAX[i + 1] == MIN[i + 1]) continue;
            long long tmp = MAX[i + 1] - sum;
            if (tmp == ans) cnt += cntMax[i + 1];
            else {
                if (tmp > ans) {
                    cnt = cntMax[i + 1];
                    ans = tmp;
                }
            }
        }
    }
    bfile << ans << '\t' << cnt;

    afile.close();
    bfile.close();
}
