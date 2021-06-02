T = int(input())

fib = [0, 1]
for i in range(2, 41):
    fib.append(fib[i-1]+fib[i-2])

for i in range(T):
    n = int(input())
    if n == 0:
        print(1, 0)
    else:
        print(fib[n-1], fib[n])
