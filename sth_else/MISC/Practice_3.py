import math

# INTERCHANGE SORT and LINEAR SEARCH
#def interchange_sort(a):
#    n = len(a)

#    for i in range(n - 1):
#        for j in range(i, n):
#            if a[i] > a[j]:
#                temp = a[i]
#                a[i] = a[j]
#                a[j] = temp
#    return a

#def linear_search(a, k):
#    for i in range(len(a)):
#        if a[i] == k: return i
#    return -1
        

#a = []

#while True:
#    x = int(input())
#    if (x >= 0): a.append(x)
#    else: break

#print("1: Interchange Sort")
#print("2: Linear search")

#choice = int(input("Your choice:"))

#if choice == 1:
#    print(a)
#    a = interchange_sort(a)
#    print(a)
#elif choice == 2:
#    k = int(input("Key: "))
#    result = linear_search(a, k)
#    if result == -1: print(k, "does not exist in a")
#    else: print(k, "found in", result)
#--------------------------------------
# Solving a quadratic equation aka Giai phuong trinh bac 2 in Vietnamese
#a = int(input("a = "))
#b = int(input("b = "))
#c = int(input("c = "))

#def delta(a, b, c):
#    return b**2 - 4 * a * c

#def solve(a, b, c):
#    if a == 0:
#        if b == 0: print("There are no solutions for this equation")
#        else:
#            if c == 0: print("There is 1 solution for this equation, x = 0")
#            else:
#                x = -b / 2 * a
#                print("There is 1 solution for this equation, x = {}".format(x))
#        return
#    d = delta(a, b, c)
#    if d > 0:
#        x1 = (-b + math.sqrt(d)) / (2 * a)
#        x2 = (-b - math.sqrt(d)) / (2 * a)
#        print("There are 2 solutions for this equation, x1 = {} and x2 = {}".format(x1, x2))
#    elif d == 0:
#        x = -b / (2 * a)
#        print("There is 1 solution for this equation, x1 = x2 = {}".format(x))
#    else: print("There are no solution for this equation")

#solve(a, b, c)
#--------------------------------------
# Calculate Greatest Common Divisor (GCD) and Lowest Common Multiply (LCM) of 2 integers.
#def GCD(a, b):
#    c = a % b
#    while (c != 0):
#        a = b
#        b = c
#        c = a % b
#    return b

#def LCM(a, b):
#    return (a * b) // GCD(a, b)

#print("GCD(a, b) =", GCD(a, b))
#print("LCM(a, b) =", LCM(a, b))
#--------------------------------------
# Calculate the diagonal matrix n x n
#n = int(input())

#a = []

#main = 0
#subt = 0

#for i in range(0, n):
#    b = []
#    for j in range(0, n):
#        x = int(input())
#        b.append(x)
#    a.append(b)

#for i in range(0, n):
#    for j in range(0, n):
#        if i == j: main += a[i][j]

#i = n - 1
#j = 0

#while (i >= 0):
#    subt += a[i][j]
#    i -= 1
#    j += 1

#print(abs(main - subt))
#--------------------------------------
#a = []
#b = []

#def nhap_diem(array):
#    for i in range(0, 3):
#        x = int(input())
#        array.append(x)

#    return array

#nhap_diem(a)
#nhap_diem(b)

#diem_an = 0
#diem_bi = 0
#diem_ho = 0
#for i in range(0, 3):
#    if a[i] > b[i]: diem_an += 1
#    if a[i] == b[i]: diem_ho += 1
#    if a[i] < b[i]: diem_bi += 1

#if diem_an > diem_bi: print("An")
#elif diem_an < diem_bi: print("Binh")
#else: print("Khong")
#--------------------------------------
#a = int(input())
#b = int(input())
#c = int(input())
#result_count = 0

#def delta(a, b, c):
#    return b**2 - 4 * a * c

#d = delta(a, b, c)
#if d > 0:
#    x1 = (-b + math.sqrt(d)) / (2 * a)
#    if x1 > 0: result_count += 2
#    elif x1 == 0: result_count += 1
#    x2 = (-b - math.sqrt(d)) / (2 * a)
#    if x2 > 0: result_count += 2
#    elif x2 == 0: result_count += 1
#elif d == 0:
#    x = -b / (2 * a)
#    if x > 0: result_count += 2
#    elif x == 0: result_count += 1


#print(result_count)
#--------------------------------------
#an_odd = []
#no_odd = []

#n = int(input())

#for i in range(n):
#    x = int(input())
#    if x % 2 == 0: an_odd.append(x)
#    else: no_odd.append(x)

#def sort(array, odd = True):
#    for i in range(len(array) - 1):
#        for j in range(i, len(array)):
#            if odd:
#                if array[i] > array[j]:
#                    temp = array[i]
#                    array[i] = array[j]
#                    array[j] = temp
#            else:
#                 if array[i] < array[j]:
#                    temp = array[i]
#                    array[i] = array[j]
#                    array[j] = temp
#    return array

#an_odd = sort(an_odd)
#no_odd = sort(no_odd, False)

#result = []
#result.append(an_odd)
#result.append(no_odd)

#for i in range(len(result)):
#    for j in range(len(result[i])):
#        print(result[i][j])
#--------------------------------------
## Calculate factorial of n
#def factorial(n):
#    if n == 1: return 1
#    else: return n * factorial(n - 1)

## Calculate combination of n and k
#def combination(n, k):
#    return int(factorial(n) / (factorial(n - k) * factorial(k)))

#n = int(input())
#k = int(input())

#print(combination(n, k))