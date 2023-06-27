import sys
input = sys.stdin.readline

m,n = map(int, input().split())
l = []
for i in range(m):
  l.append(0)
for i in range(n):
  a,b,c = map(int, input().split())
  for j in (a-1, b):
    l[j] = c
for i in l:
  print(i, end=" ")
# 왜 답이 틀리게 나오는지 이해가 안 됨