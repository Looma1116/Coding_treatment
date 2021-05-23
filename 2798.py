N, M = map(int, input().split())

Card = [int(data) for data in input().split()]
max = int(0)

for i in range(N):
    for j in range(i+1, N):
        for n in range(j+1, N):
            Sum = Card[i]+Card[j]+Card[n]
            if Sum > max and Sum <= M:
                max = Sum
print(max)
