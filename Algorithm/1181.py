N = int(input())
A = list()
for i in range(N):
    A.append(input())
A = list(set(A))


def StrCom(str1, str2):
    if len(str1) < len(str2):
        return True
    if len(str1) > len(str2):
        return False
    if len(str1) == len(str2):
        if str1 < str2:
            return True
        else:
            return False


def QuickSort(A, start, end):
    if start >= end:
        return

    pivot = int(start)
    i = int(start+1)
    j = end

    while True:
        while (i < end and StrCom(A[i], A[pivot])):
            i += 1
        while(j > pivot and StrCom(A[pivot], A[j])):
            j -= 1
        if i >= j:
            tmp = A[j]
            A[j] = A[pivot]
            A[pivot] = tmp
            break
        tmp = A[i]
        A[i] = A[j]
        A[j] = tmp

    QuickSort(A, start, j-1)
    QuickSort(A, j+1, end)


QuickSort(A, 0, len(A)-1)
for i in A:
    print(i)
