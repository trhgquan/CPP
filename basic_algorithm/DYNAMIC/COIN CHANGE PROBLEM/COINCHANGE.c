#include <stdio.h>
#include <conio.h>

// Maximum storage.
#define COIN_MAX 10001

// Global variables declaration
// amount - amount of $ need to be transfered into coins.
// ways   - store how it got transfered.
// Trace  - store the way it transfered.
// coins  - store the coins.
int amount,
    Trace[COIN_MAX],
    ways[COIN_MAX],
    coins[4] = {0, 1, 2, 5};

// List of functions using in this program.
// Details: look below.
int min(int a, int b);
void Initialize();
void ChangeCoins();
void PrintResult();

int main(int argc, char const *argv[]) {
    // Input amount to convert
    printf("Amount to convert: "); scanf("%d", &amount);

    // Change it to coins.
    ChangeCoins();

    // And print the result to the screen
    printf("Minimum number of coins required: %d\n", ways[amount]);
    PrintResult();

    return 0;
}

/**
 * Return the smaller in 2 number
 * @param a: first number
 * @param b: second number
 * @return the smaller in these 2 number.
 */
int min(int a, int b) {
    return (a > b) ? b : a;
}

/**
 * Initalize result table and trace tracking table.
 */
void Initialize() {
    // Result table initialize
    for (int i = 1; i <= amount; ++i) ways[i] = amount + 1;
    // We need 0 coin for 0$
    ways[0] = 0;

    // Trace table initialize
    for (int i = 0; i <= amount; ++i) Trace[i] = 0;
}

/**
 * Change $ into coins.
 * this required the Initialize method, upper there.
 */
void ChangeCoins() {
    // Initialize the Result table and Trace tracking.
    Initialize();

    for (int i = 1; i <= amount; ++i)
        // At here, (sizeof(coins)/sizeof(coins[0])) return the array's length.
        for (unsigned int j = 1; j <= (sizeof(coins) / sizeof(coins[0])); ++j) {
            // If the coin is larger than the amount we need, skip it.
            if (i - coins[j] < 0) break;
            else {
                // If this choice is better than the nearest choice,
                // choose it.
                if (ways[i - coins[j]] + 1 < ways[i]) {
                    ways[i] = min(ways[i - coins[j]] + 1, ways[i]);
                    // Remember to trace it.
                    Trace[i] = i - coins[j];
                }
            }
        }
}

/**
 * Print result, using trace tracking.
 * This will print out each coin, then a space.
 * Note that you can use an array to store the amount of each coins,
 * then print it out instead of using this.
 */
void PrintResult() {
    int i = amount;
    while (i != 0) {
        printf("%d ", i - Trace[i]);
        i = Trace[i];
    }
}
