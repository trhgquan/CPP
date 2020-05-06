#include <iostream>

int main() {
    int origin, i = 0;

    std::cout << "Type a number" << '\n';
    std::cin >> origin;

    while (origin > 0) { // loop until origin number smaller than 0. ex: 300 -> 30 -> 3 -> 0(.3) 
        std::cout << origin % 10 << '\n';
        origin /= 10;
        i++;
    }

    std::cout << i << '\n';
    return 0;
}
