/**
 * This is an example for function pointer,
 *
 * CS102 practice only.
 */

#include<stdio.h>

/**
 * Add two integer.
 * @param  a First integer.
 * @param  b Second integer.
 * @return   Sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * Substract two integer.
 * @param  a Number to be substracted.
 * @param  b Number to be substracted from a.
 * @return   Result of a substracts b.
 */
int sub(int a, int b) {
    return a - b;
}

/**
 * Define a function pointer:
 * A function receive two integer, return an integer.
 *
 * Notice that this is just a function_template,
 * any function that receives two integer and return one integer
 * will fit this.
 */
typedef int (*calculate_two_integer)(int, int);

/**
 * This function using a function as an operator.
 * @param  x         First integer
 * @param  y         Second integer
 * @param  operation Operation function
 * @return           an integer, result.
 */
int calculate(int x, int y, calculate_two_integer operation) {
    return operation(x, y);
}

int main() {
    // Two initalise value.
    int x = 10;
    int y = 20;

    // This pass a function as a parameter to another function.
    int addition  = calculate(x, y, add);
    int substract = calculate(x, y, sub);

    // Print the result.
    printf("x = %d, y = %d\naddition = %d\nsubstract = %d", x, y, addition, substract);
    return 0;
}
