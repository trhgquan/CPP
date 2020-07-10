##
## The Polish Postfix Notation Calculator
##
## Code by @trhgquan - https://github.com/trhgquan
## 

# Uncomment the code below if you use deque
from collections import deque

# Uncomment the code below if you use LifoQueue
#from queue import LifoQueue

# Declare the math signs
mathSigns = ["+", "-", "*", "/"]

# Simple Calculation function.
def calculate(number_1, number_2, sign):
    # Plus:
    if sign == '+': return number_1 + number_2
    # Minus:
    elif sign == '-': return number_1 - number_2
    # Multiply:
    elif sign == '*': return number_1 * number_2
    # Divide:
    else: return number_1 / number_2

def PolishNotation_postfix(notation):
    # Define a Polish Stack list. This does NOT require any library

    #polishStack = []

    # Or, using deque (collections)
    polishStack = deque()

    # Or, using LifoQueue
    #polishStack = LifoQueue()

    # This variable store a number with many characters.
    # When reading a string, '10' can be read into '1' and '0',
    # so this prevent it happens.

    numTemp = ''

    for character in notation:
        # Meet a space aka a number is read.
        if character == ' ':
            if len(numTemp) > 0:
                # Uncomment the code below if you use list or deque
                polishStack.append(int(numTemp))

                # Uncomment the code below if you use LifoQueue
                #polishStack.put_nowait(int(numTemp))

            numTemp = ''
        else:
            if not character in mathSigns:
                # This means "character" is a number.
                numTemp += str(character)
            else:
                # This means "character" is a math sign
                # Note: in Polish Postfix, [item1, item2] means item2 *doing something* item1

                # Uncomment the code below if you use list or deque
                number_2 = polishStack.pop()
                number_1 = polishStack.pop()
                polishStack.append(calculate(number_1, number_2, character))

                # Uncomment the code below if you use LifoQueue
                #number_2 = polishStack.get_nowait()
                #number_1 = polishStack.get_nowait()
                #polishStack.put_nowait(calculate(number_1, number_2, character))

    # The Stack's top item is the result.

    # Uncomment the code below if you use list or deque
    return polishStack.pop()

    # Uncomment the code below if you use LifoQueue
    #return polishStack.get_nowait()

testCases = [
    '1 1 +', # Result: 2
    '2 3 + 4 *', # Result: 20
    '10 5 + 3 *', # Result: 45

    # add more testcases here
]

for notations in testCases:
    print("polish notation postfix \"{}\"\nresult: {}".format(notations, PolishNotation_postfix(notations)))
