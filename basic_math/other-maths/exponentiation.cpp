#include "iostream"

int main()
{
    int input, output, i;

    std::cout << "Type the exponentiation number of 2: " << "\n";
    std::cin >> input;

    output = 1;

    for (i = 1; i <= input; i++) {
        output *= 2;
        std::cout << i << " => " << output << '\n';
    }

    std::cout << "Result: " << output;
    return 0;
}
