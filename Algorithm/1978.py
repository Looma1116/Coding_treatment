def NotPrimeNum(N):
    r = int(0)
    if N == 1:
        return True
    for i in range(2, N):
        if N % i == 0:
            r += 1
    if r > 0:
        return True
    else:
        return False


N = int(input())
A = list(map(int, input().split()))

M = int(0)

for i in range(N):
    if NotPrimeNum(A[i]):
        M += 0
    else:
        M += 1

print(M)
