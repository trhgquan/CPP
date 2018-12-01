#include <iostream>

using namespace std;

int n, total_steps = 0;

void swap (int disks, char col_from, char col_to, char col_mid);

int main () {
    cout << "Number of disks:";
    cin >> n;

    // recursion
    swap(n, 'A', 'C', 'B');

    cout << "Total steps: " << total_steps;

    return 0;
}

void swap (int disks, char col_from, char col_to, char col_mid)
{
    ++total_steps;
    if (disks == 1)
        cout << "Move disk " << disks << " from " << col_from << " to " << col_to << '\n';
    else {
        swap(disks - 1, col_from, col_mid, col_to);
        cout << "Move disk " << disks << " from " << col_from << " to " << col_to << '\n';
        swap(disks - 1, col_mid, col_to, col_from);
    }
}
