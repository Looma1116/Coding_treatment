N = int(input())

D = [[0 for i in range(3)] for j in range(N+1)]
I = [0 for i in range(3)]  # 입력 받는 리스트
for i in range(1, N+1):
    I[0], I[1], I[2] = map(int, input().split())  # R G B 가격
    for j in range(3):
        # i번째 집까지 칠하는 각 RGB색깔 별 최소값은, 입력 받은 가격에 i-1 번째 집의 경우의 수 중 그 색깔과 겹치지 않는 경우 두 경우 중 작은 값을 더한 값
        D[i][j] = I[j] + min(D[i-1][j-1], D[i-1][j-2])

print(min(D[N][0], D[N][1], D[N][2]))
