import math

n = input()
digit = list()
flag = int(0)
while True:
    if n == '0':
        break
    flag = int(0)
    L = len(n)
    n = int(n)
    for i in range(L-1):
        digit.append(n % 10)
        n = math.floor(n/10)
    digit.append(n)
    for i in range(math.floor(L/2)):
        if digit[i] != digit[L-i-1]:
            flag += 1
    if flag > 0:
        print('no')
    else:
        print('yes')
    del digit[:]
    n = input()
