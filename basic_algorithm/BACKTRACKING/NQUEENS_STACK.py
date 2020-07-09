##
## NQUEENS - Stack implementation
##
## Code by @trhgquan - https://github.com/trhgquan
##

from collections import deque
import time

# Function to solve.
def NQUEENS(tableSize):
    # Create a stack to store all positions.
    queenStack = deque()

    # Push first cell to visit [0, 0]
    queenStack.append(0)

    # This variable store the position of the previous queen.
    previousQueen = -1

    # While the stack is not empty,
    # placing the queens.
    while len(queenStack) > 0:
        # Reach the target! All queens have been placed safely.
        # Now we print the table.
        if len(queenStack) == tableSize:
            printQueens(queenStack)

        # If all queens aren't on the table,
        # find a way to place the rest of them.
        else:
            # Look for a valid column from the previous queen.
            validColumn = lookForValidColumn(previousQueen, tableSize, queenStack)

            # If there still have a valid column, push it to the stack.
            if validColumn >= 0:
                queenStack.append(validColumn)
                previousQueen = -1

            # Else, pop the old column to backtrack.
            else:
                previousQueen = queenStack.pop()

def isValidCell(row, col, queens):
    # Look through all queens in the stacks.
    # If there are conflict, we'll not choose that cell.
    for j in range(0, len(queens)):
        # Column of the j-position queen.
        stackQueenX = queens[j]

        # Row of the j-position queen, also j.
        stackQueenY = j

        # Conflict happened - don't choose this cell.
        if (col == stackQueenX) or (col - stackQueenX == row - stackQueenY) or (row + col == stackQueenX + stackQueenY):
            return False

    # Yes, can place so we can choose this cell.
    return True

# Look for a valid position at this row.
def lookForValidColumn(previousStep, limit, queens):
    # Check from current position to back.
    for possibleCol in range(previousStep + 1, limit):
        col = possibleCol
        row = len(queens)

        # If that cell is valid, return it.
        if isValidCell(row, col, queens):
            return col

    # No cell valid.
    return -1

# Print the queen.
def printQueens(queens):
    countQueen = 0
    while len(queens) > 0:
        # Since we are counting from 0, plus 1 give us the real position of the cell.
        print("[{}, {}]".format(countQueen + 1, queens.pop() + 1))
        countQueen += 1

if __name__ == "__main__":
    tableSize = int(input("Table size & queens = "))

    # Get execution time
    startTime = time.time()

    # Find a solution
    NQUEENS(tableSize)

    # Print execution time.
    print("Execution time: {} seconds".format(time.time() - startTime))
