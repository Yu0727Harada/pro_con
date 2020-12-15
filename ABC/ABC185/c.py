from math import factorialr


l = int(input())
n = l -1
r = 11
print(factorial(n) // factorial(r) // factorial(n - r))