import sys
input = sys.stdin.readline

a = int(input())
l2 = []
for i in range(a):
    l = list(map(int, input().split()))
    total = 0
    for j in range(l[0]):
        total += l[j+1]
    average = total / l[0]
    success = 0
    for j in range(1, len(l)):
        if(average < l[j]):
            success+=1
    l2.append(round(success/l[0]*100, 3))
for i in l2:
    print(i, end="")
    print("%")