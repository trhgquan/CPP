# List of coins.
# Note: number of coins each type is infinity.
coins = [1, 2, 5]

# Program to find minimum number of coins needed
# using DP (Dynamic Programming) approach.
def minimum(amount):
    # Initialize
    ways = [amount] * (amount + 1)
    # 0$ needed 0 coin to convert.
    ways[0] = 0

    # Check from the first list item.
    for i in range(1, amount + 1):
        # Try every coin:
        for j in range(len(coins)):
            # If the coin is larger than the value, then skip it.
            if i - coins[j] < 0: break
            else:
                if ways[i - coins[j]] < amount:
                    ways[i] = min(ways[i - coins[j]] + 1, ways[i])

    print("Minimum number of coins needed: {}".format(ways[amount]))

amount = int(input("Amount of $: "))
minimum(amount)
