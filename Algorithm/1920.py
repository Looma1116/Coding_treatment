from collections import Counter

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

A = Counter(A)

for i in range(M):
    if A[B[i]]:
        print("1")
    else:
        print("0")
