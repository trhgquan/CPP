import math
# VNSIGMA TEST CHAPTER 2.
#--------------------------------------------------
## 1: Calculate the area of a circle

#def area(R):
#    pi = math.pi
#    return (R ** 2) * pi

#R = int(input())
#print(area(R))

#--------------------------------------------------
## 2: Calculate sum of even number smaller than n

#def isOdd(k):
#    return k % 2 != 0

#n = int(input())
#s = 0

#for i in range(1, n):
#    if isOdd(i): s += i

#print(s)

#--------------------------------------------------
## 3: Check if a string is an ID number.
## An ID number string must have 8 numberic characters only.
## We don't use a.isalnum() because in this chapter we haven't learn how to use string methods.
## Cost me 3 submits to realised.

#def isAllNumber(a):
#    for i in a:
#        if i >= '0' and i <= '9': continue 
#        else: return False
#    return True

#def checkNumLength(a):
#    return len(a) == 9

#testCases = [
#    '012345678',
#    '01234567!',
#    '000000000',
#    '!339872239823728937'
#]

#for a in testCases:
#    print(isAllNumber(a) and checkNumLength(a))

#--------------------------------------------------
## 4: Calculate the multiply of 2 complex number.
#def multComplexNum(a,b,c,d):
#   real = (a * c) - (b * d)
#   flot = (a * d) + (b * c)
#   print(real, flot)

#a = int(input())
#b = int(input())
#c = int(input())
#d = int(input())
#multComplexNum(a,b,c,d)
