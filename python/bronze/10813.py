import sys
input = sys.stdin.readline

m,n = map(int, input().split())
l = []
for i in range(m):
  l.append(i+1)
for i in range(n):
  a,b = map(int, input().split())
  t = l[a-1]
  l[a-1] = l[b-1]
  l[b-1] = t
for i in l:
  print(i, end=" ")