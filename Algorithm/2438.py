a = int(input())
i = 0
j = 0
for i in range(a):
    for j in range(i+1):
        print("*", end='')
    print()