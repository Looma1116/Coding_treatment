import math


def isPrime(A, M):
    for i in range(2, int(math.sqrt(M))+1):
        if A[i] == 0:
            continue
        for j in range(i*i, M+1, i):
            A[j] = 0


N, M = map(int, input().split())

A = [data for data in range(M+1)]
A[1] = 0
isPrime(A, M)

for i in range(N, M+1):
    if A[i] != 0:
        print(A[i])
