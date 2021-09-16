N, M = map(int, input().split())
Dogam = {}
reDogam = {}
for i in range(1, N+1):
    pokemon = input()
    Dogam[i] = pokemon
    reDogam[pokemon] = i

#reversed_Dogam = dict(map(reversed,Dogam.items()))

for i in range(M):
    x = input()
    if str.isdigit(x):
        print(Dogam[int(x)])
    else:
        print(reDogam[x])
        # print(reversed_Dogam[x])
