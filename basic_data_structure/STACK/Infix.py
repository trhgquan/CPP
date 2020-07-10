##
## Infix notation calculator
##
## Code by @trhgquan - https://github.com/trhgquan
## 

from collections import deque

# Math operators
mathOperators = ["+", "-", "*", "/"]

# Function to calculate a math operation.
def calculate(firstOperand, secondOperand, operator):
    # Plus operator
    if operator == '+':
        return firstOperand + secondOperand
    # Minus operator
    elif operator == '-':
        return firstOperand - secondOperand
    # Multiply operator
    elif operator == '*':
        return firstOperand * secondOperand
    # Divide operator
    return firstOperand / secondOperand

def infixNotation(notation):
    infixStack = deque()

    numTemp = ''

    for element in notation:

        if element != ')':
            # Element is a number,
            # but since we are reading each characters at once,
            # this is the way to recognise multicharacters numbers.
            if (not element in mathOperators) and (element != '(') and (element != ' '):
                numTemp += str(element)

            if (element in mathOperators) or (element == '(') or (element == ' '):
                # Append the number
                if len(numTemp) > 0:
                    infixStack.append(int(numTemp))
                    numTemp = ''

                # Append the math operator / the opening bracket.
                if (element != ' '): infixStack.append(element)

        else:
            # If the temp is not empty aka still has a number left, then push it to the stack.
            if len(numTemp) > 0:
                infixStack.append(int(numTemp))
                numTemp = ''

            # Pop the top of the stack.
            topStack = infixStack.pop()

            # Since we don't operate anything with the opening bracket "(",
            # pass it.
            if topStack == '(': continue
            else:
                # Calculate in bracket value
                secondOperand = topStack
                operator = infixStack.pop()
                firstOperand = infixStack.pop()

                # Pop stack to eliminate the '('
                infixStack.pop()

                # Insert the value back to stack.
                infixStack.append(calculate(firstOperand, secondOperand, operator))

    return infixStack.pop()

if __name__ == "__main__":
    notations = [
        "( ( 2 * ( 4 + 3 ) ) / ( 2 + 5 ) )",
        "( ( ( 1 + 2 ) * ( 3 * 4 ) ) * (5 + 5) )",
        # Add more here.
    ]

    for notation in notations:
        print("{} = {}".format(notation, infixNotation(notation)))
