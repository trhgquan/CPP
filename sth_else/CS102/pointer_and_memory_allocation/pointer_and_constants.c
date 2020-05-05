#include<stdio.h>

int main() {
    int x = 5;
    int* const p = &x;
    const int* q = &x;

    printf("x has address %p, has value %d\n", &x, x);
    printf("p is storing %p, has value %d\n", p, *p);
    printf("q is storing %p, has value %d\n", q, *q);

    int y = 6;
    q = &y; // can't do: *q = y
    *p = y; // can't do: p = &y

    printf("x has address %p, has value %d\n", &x, x);
    printf("p is storing %p, has value %d\n", p, *p);
    printf("q is storing %p, has value %d\n", q, *q);

    /**
     * Overall, you can't change what a const* pointer point to,
     * and can't change the value of what *const point to.
     */


    return 0;
}
