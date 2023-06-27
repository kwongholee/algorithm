import sys
input = sys.stdin.readline

m, n = map(int, input().split())
l = []
for i in range(m):
  l.append(i+1)
for i in range(n):
  a,b = map(int, input().split())
  sample = []
  for j in range(a-1, b):
    sample.append(l[a+b-2-j])
  for j in range(b-a+1):
    l[j+a-1] = sample[j]
for i in l:
  print(i, end=" ")