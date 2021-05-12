a=[]
for i in range(9):
    a.append(int(input()))
max = 0
for i in range(9):
    if a[i] > max:
        max = a[i]

print(max)
print(a.index(max)+1)