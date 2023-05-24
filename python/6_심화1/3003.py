import sys
input = sys.stdin.readline

l1 = [1,1,2,2,2,8]
l2 = list(map(int, input().split()))
for i in range(6):
    print(l1[i]-l2[i], end=" ")