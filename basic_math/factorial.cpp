#include <iostream>

using namespace std;

// write the recursion function in here.
// NEVER: write function after the main.
int recursion (int input)
{
    if (input > 1)
        return input * recursion(input - 1);
    return 1;
}

int main ()
{
    int input;

    cout << "Please type your input:";
    cin  >> input;

    cout << "Result: " << recursion(input);
    return 0;
}
