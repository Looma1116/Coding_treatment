import math

n, k = input().split()
n = int(n)
k = int(k)
c = math.factorial(n)/math.factorial(n-k)/math.factorial(k)
print(int(c))