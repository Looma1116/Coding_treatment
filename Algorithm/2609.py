N, M = map(int, input().split())


def EuclidDiv(N, M):
    while True:
        D = N % M
        if D == 0:
            return M
        N = M
        M = D


print(EuclidDiv(N, M))
print(M*N//EuclidDiv(N, M))
