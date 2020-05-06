#include <iostream>

using namespace std;

bool is_songuyen (int so)
{
    int i, chiahet = 0;

    for (i = 1; i <= so; i++) {
        if (so % i == 0)
            chiahet++;
    }

    if (chiahet <= 2 && so != 1)
        return true;
    return false;
}

int main()
{
    // dem xem tu 1 den num co bao nhieu so nguyen to
    short int num, i;

    cout << "Moi ban nhap vao max!" << "\n";
    cin >> num; // nhap number vao tu ban phim;

    int tong = 0, max;

    for (i = 2; i <= num; i++)
    {
        if (is_songuyen(i))
        {
            tong++;
            max = i;
        }
    }

    cout << "co " << tong << " so nguyen to trong khoang tu 1 den " << num << '\n';
    cout << "so nguyen to lon nhat trong day la " << max << '\n';

    return 0;
}
