N = int(input())
x = 0
for i in range(N):
    R, S=input().split()
    R = int(R)
    for x in range(len(S)):
        print(S[x]*R, end='')
    print()