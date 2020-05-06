#include "iostream"

int main() {
    int a,b;

    std::cout << "Nhap so a: " << '\n';
    std::cin >> a; // Nhap so a tu ban phim

    std::cout << "Nhap so b: " << '\n';
    std::cin >> b; // Nhap so b tu ban phim

    // Dua ra so lon hon trong 2 so a va b ma khong can dung cau truc re nhanh.
    std::cout << ((a+b)+abs(a-b)) / 2 << '\n';

    return 0;
}
