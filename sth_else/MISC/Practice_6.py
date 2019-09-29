# CHAPTER 3 TEST - VNSIGMA PYTHON.
#---------------------------
## 1: Find the max in 4 numbers.

#a = int(input())
#b = int(input())
#c = int(input())
#d = int(input())

#print(max(a, b, c, d))

#---------------------------
## 2: Given number x. If x > 0, print "+", x < 0 print "-". Else, print 0

#x = int(input())

#if x > 0: print("+")
#elif x < 0: print("-")
#else: print(0)

#---------------------------
## 3: Given a and b. Check if there is an integer x that is the solution of ax + b = 0
## Solution: calculate -b / a, then subtract int(-b/a). If the result is different than 0,
## then print "No".

#a = int(input())
#b = int(input())

#if a == 0: print("No")
#else: 
#    c = -b / a

#    if (c - int(c) != 0): print("No")
#    else: print("Yes")

#---------------------------
## 4: Input: date time d/m/y. Calculate the next day.
## Samples: Input 3 4 2001, output 4 4 2001
## (Remember leap year. Cost me 4 submit to realised)

#d = int(input())
#m = int(input())
#y = int(input())

#def leapY(y):
#    return ((
#        (y % 4 == 0) and (y % 100 != 0)) 
#        or 
#        ((y % 100 == 0) and (y % 400 == 0)))

#month_has_31 = [1, 3, 5, 7, 8, 10, 12]
#month_has_30 = [4, 6, 9, 11]

#if m in month_has_31:
#    if d == 31:
#        if m == 12: 
#            d = 1
#            m = 1
#            y += 1
#        else:
#            m += 1
#            d = 1
#    else: d += 1
#elif m in month_has_30:
#    if d == 30:
#        m += 1
#        d = 1
#    else: d += 1
#else:
#    if leapY(y):
#       if d == 29:
#            m += 1
#            d = 1
#       else: d += 1
#    elif not leapY(y) and d == 29:
#        m += 1
#        d = 1
#    elif d == 28:
#        m += 1
#        d = 1
#    else: d += 1

#print("{} {} {}".format(d, m, y))
#---------------------------

## HAPPY CODING!