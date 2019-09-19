# Count spare brackets
def count_spare_brackets(bracket_string):
    count = 0
    spare = 0

    for b in bracket_string:
        # If the bracket is open, then +1
        if b == '(': count += 1
        # If the bracket is close, then -1
        if b == ')': count -= 1

        # An open/close bracket is in wrong position.
        # Count it as a wrong bracket, and continue counting
        if count < 0:
            spare += 1
            count = 0

    # At here, if count > 0, means there are brackets opening without closing.
    # Count + spare brackets here, that will be the answer.
    count += spare
    return count

brackets = [
    '()',
    '()()',
    '())',
    '))()((',
    '()()()))())()()()(())()'
]

for b in brackets:
    spare = count_spare_brackets(b)
    if spare > 0: print("FAILED:", spare)
    else: print("PASSED")
