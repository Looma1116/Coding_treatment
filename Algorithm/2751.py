# Merge sort

N = int(input())

A = []
S = [0 for i in range(N)]
for i in range(0, N):
    A.append(int(input()))


def Merge(A, start, end):
    mid = (end + start)//2
    i = start
    k = start
    j = 1 + mid
    while i <= mid and j <= end:
        if A[i] < A[j]:
            S[k] = A[i]
            i += 1
        else:
            S[k] = A[j]
            j += 1
        k += 1
    if j > end:
        while i <= mid:
            S[k] = A[i]
            k += 1
            i += 1
    else:
        while j <= end:
            S[k] = A[j]
            k += 1
            j += 1
    for p in range(start, end+1):
        A[p] = S[p]


def MergeSort(A, start, end):
    if end > start:
        mid = (end + start)//2
        MergeSort(A, start, mid)
        MergeSort(A, mid+1, end)
        Merge(A, start, end)


MergeSort(A, 0, N-1)

for i in range(0, N):
    print(A[i])
