import sys
sys.setrecursionlimit(10000)


def next(arr, i, j):  # 인접한 배추 찾기
    global group
    if arr[i][j] == 0:  # 배추 없으면 return
        return
    else:  # 배추있으면 group는 1, 배추는 0으로 바꾸기
        arr[i][j] = 0
        group = 1
    if i == N or j == M:
        return
    if i >= 1:  # 가장자리는 인덱스 넘어가니까 조건문
        next(arr, i-1, j)
    if i < N-1:
        next(arr, i+1, j)
    if j >= 1:
        next(arr, i, j-1)
    if j < M-1:
        next(arr, i, j+1)


T = int(input())
for t in range(T):
    Jirung = int(0)  # 지렁이 초기화
    M, N, K = map(int, input().split())

    field = [[0 for x in range(M)]for y in range(N)]
    for i in range(K):
        x, y = map(int, input().split())  # 좌표 받기
        field[y][x] = 1  # 배추 심기
    for x in range(M):
        for y in range(N):
            group = int(0)
            next(field, y, x)
            if group == 1:
                Jirung += 1
    print(Jirung)
