# THIS CALCULATE Polish Prefix Notation

# Uncomment the code below if you use deque
from collections import deque

# Uncomment the code below if you use LifoQueue
#from queue import LifoQueue

# Declare the math signs
mathSigns = ["+", "-", "*", "/"]

# Simple Calculation function.
def calculate(number_1, number_2, sign):
    if sign == '+': return number_1 + number_2   # Plus
    elif sign == '-': return number_1 - number_2 # Minus
    elif sign == '*': return number_1 * number_2 # Multiply
    else: return number_1 / number_2             # Divide

def PolishNotation_prefix(notation):
    # Uncomment the code below if you use list
    #polishStack = []

    # Uncomment the code below if you use deque (collections)
    polishStack = deque()

    # Uncomment the code below if you use LifoQueue
    #polishStack = LifoQueue()

    numTemp = ''

    # For prefix notation, we read the notation from end to start.
    for i in range(len(notation) - 1, -1, -1):
        character = notation[i]
        
        if character == ' ':
            if len(numTemp) > 0: 
                # Uncomment if you use list or deque
                polishStack.append(int(numTemp))

                # Uncomment if you use LifoQueue
                #polishStack.put_nowait(int(numTemp))
            numTemp = ''
        else:
            if character in mathSigns:
                # Uncomment if you use list or deque
                number_1 = polishStack.pop()
                number_2 = polishStack.pop()
                polishStack.append(calculate(number_1, number_2, character))

                # Uncomment if you use LifoQueue
                #number_1 = polishStack.get_nowait()
                #number_2 = polishStack.get_nowait()
                #polishStack.put_nowait(calculate(number_1, number_2, character))
            else:
                numTemp = character + numTemp

    # Last item is the answer

    # Uncomment if you use list or deque
    return polishStack.pop()

    # Uncomment if you use LifoQueue
    #return polishStack.get_nowait()

testCases = [
    '* + - 10 1 1 + 20 10', # Result: 300
    '/ * 10 10 4',          # Result: 25
    '* + 5 2 - 5 2',        # Result: 21
    
    # add more testcases here
]

for notations in testCases:
    print("polish notation prefix \"{}\"\nresult: {}".format(notations, PolishNotation_prefix(notations)))
