import sys
input = sys.stdin.readline

a = int(input())
l = []
for i in range(a):
  b,c = input().split()
  b = int(b)
  l1 = [b, c]
  l.append(l1)
for i in range(len(l)):
  cnt = l[i][0]
  for j in range(len(l[i][1])):
    print(cnt*l[i][1][j], end="")
  print()