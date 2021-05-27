from collections import deque
N, K = map(int, input().split())
A = deque()
for data in range(1, N+1):
    A.append(data)

print('<', end="")
for i in range(N-1):
    A.rotate(-(K-1))
    print(A[0], end="")
    print(', ', end="")
    A.popleft()

print(A[0], '>', sep='')
