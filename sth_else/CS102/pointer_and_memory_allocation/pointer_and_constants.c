/**
 * This is a small example for * const (pointer to constant) and const * (constant pointer).
 *
 * CS102 practice only.
 */

#include<stdio.h>

int main() {
    int x = 5;
    int* const p = &x; // This called "constant pointer".
    const int* q = &x; // This called "pointer to a constant".

    printf("x has address %p, has value %d\n", &x, x);
    printf("p is storing %p, has value %d\n", p, *p);
    printf("q is storing %p, has value %d\n", q, *q);

    int y = 6;
    *p = y; // can't do: p = &y
    q = &y; // can't do: *q = y

    printf("x has address %p, has value %d\n", &x, x);
    printf("p is storing %p, has value %d\n", p, *p);
    printf("q is storing %p, has value %d\n", q, *q);

    /**
     * Overall:
     * you can't change what a *const pointer point to,
     *     can't change the value of what const* point to.
     */


    return 0;
}
