N, M = map(int, input().split())
B = [[0 for i in range(M)] for j in range(N)]


def Chess(board, n, m):
    num = int(0)
    min = int(2500)
    flag = int(1)  # 첫 칸이 검정색인 체스판 만들면
    for twice in range(2):
        for a in range(n-7):  # 체스판안에서
            for b in range(m-7):  # 8*8의 모든 경우의 수 탐색
                for i in range(8):  # 선택 된
                    for j in range(8):  # 8*8에서 탐색
                        if(flag == 0):  # flag가 0일땐 W여야 함
                            if(board[a+i][b+j] == 'B'):
                                num += 1
                        else:  # 1일 때 B여야 함
                            if(board[a+i][b+j] == 'W'):
                                num += 1
                        flag = 0 if flag else 1  # 다음 칸은 다른 색
                    flag = 0 if flag else 1  # 다음 줄의 첫번째 칸은 다른 색
                min = num if min > num else min
                num = int(0)
        flag = 0  # 첫 칸이 흰색인 체스판 만들면
    return min  # 최소 색칠 횟수 return


for i in range(N):
    str = input()  # 한줄 씩 간격 없이 입력
    for j in range(M):
        B[i][j] = str[j]  # 을 보드 배열에 한 글자 씩 넣기


print(Chess(B, N, M))

# >>10 13 => 크기 입력
# >>
# BBBBBBBBWBWBW
# BBBBBBBBBWBWB
# BBBBBBBBWBWBW
# BBBBBBBBBWBWB
# BBBBBBBBWBWBW
# BBBBBBBBBWBWB
# BBBBBBBBWBWBW
# BBBBBBBBBWBWB
# WWWWWWWWWWBWB
# WWWWWWWWWWBWB => 체스판 입력

# 출력 : 횟수
