/**
 * In the problem's theory, we get:
 *  f(0) = 0
 *  f(1) = 1
 *  f(2) = 2
 *  f(op) = 0
 *  and f(a*b) = f(a) + f(b) for a + b = min.
 *
 * For example,
 * f(15) = f(3*5) = f(3) + f(5). Because 3 and 5 is odd prime (op), so f(3) + f(5) = 0 + 0 = 0.
 * f(8)  = f(2*4) = f(2) + f(4) = f(2) + f(2) + f(2) = 2 + 2 + 2 = 6.
 *
 * From 2 examples above:
 * ++ Odd numbers will result in 0. This could be proved easily using some mathematics, since an odd number can be divided into two smaller odd numbers, which f(x) result 0.
 * ++ Even numbers will result in 2* //something//, which //something// is what we can easily find by a simple loop:
 *  while (number is even)
 *      something = something + 1
 *      number = number divided to 2
 *  endwhile.
 */

#include <stdio.h>

#define lli long long int

int x;

lli f (lli x) {
    if (x == 0 || x == 1 || x == 2)
        return x;
    else {
        lli answer = 0;
        while (x % 2 == 0) {
            answer = answer + 2;
            x /= 2;
        }
        return answer;
    }
}

int main() {
    scanf("%d", &x);
    printf("%I64d", f(x));
    return 0;
}
