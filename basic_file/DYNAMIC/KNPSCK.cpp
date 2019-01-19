/**
0-1 Knapsack Problem | DP-10
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Problem in a nutshell: pick some items, that the bag is not heavier than W and also cost most, aka value at max.
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("KNPSCK.inp", ios::in);
ofstream bfile("KNPSCK.out", ios::out);

int n, W;
// with value aka an item's price (or value)
int value[100], item_weight[100];

void read();
int Knapsack (int n, int W, int *item_weight, int *value);

int main() {
    read();
    bfile << Knapsack(n, W, item_weight, value);
    afile.close();
    bfile.close();
    return 0;
}

void read() {
   afile >> n >> W;

   for (int i = 0; i < n; i++)
       afile >> value[i];
   for (int i = 0; i < n; i++)
       afile >> item_weight[i];
}

int Knapsack(int n, int W, int *item_weight, int *value) {
    if (n == 0 || W == 0)
        return 0;

    if (item_weight[n - 1] > W)
        return Knapsack(n - 1, W, item_weight, value);
    else
        return max(value[n - 1] + Knapsack(n - 1, W - item_weight[n - 1], item_weight, value), Knapsack(n - 1, W, item_weight, value));
}
