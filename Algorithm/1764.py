from collections import Counter
A = list()
B = list()
C = list()

N, M = map(int, input().split())

for i in range(N):
    A.append(input())
A = Counter(A)  # 딕셔너리
for i in range(M):
    B.append(input())
for i in range(M):
    if B[i] in A.keys():
        C.append(B[i])
C.sort()
print(len(C))
for i in range(len(C)):
    print(C[i])
