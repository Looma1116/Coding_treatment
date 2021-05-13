from collections import Counter

N=int(input())

Card = list(map(int,input().split()))
M=int(input())
Have = list(map(int, input().split()))
Yes = int()
Card = Counter(Card)
for i in range(M):
    print(Card[Have[i]], end=' ')
