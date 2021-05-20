from collections import deque
N = int(input())
flag = int(0)
A = deque()

for i in range(1, N+1):
    A.append(i)

for i in range(2*(N-1)-1):
    if flag == 0:
        A.popleft()
        flag += 1
    else:
        A.append(A[0])
        A.popleft()
        flag -= 1

print(A[0])
