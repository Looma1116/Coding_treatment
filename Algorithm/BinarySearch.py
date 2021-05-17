import math


def BinarySearcher(list, find):
    start = int(0)
    end = len(list)-1
    i = int(0)
    while(start <= end):
        print("Searching depth:", i)
        i += 1
        mid = start + math.ceil((end-start)/2)
        if find > list[mid]:
            start = mid+1
        elif find < list[mid]:
            end = mid-1
        else:
            return list[mid]


List = list(map(int, input("Input Numbers with spacebar: ").split()))
List.sort()
Find = int(input("Input a finding Number: "))
print(BinarySearcher(List, Find))
