import sys
input = sys.stdin.readline

l = []
max = 0
idx = 0
for i in range(0,9):
  a = int(input())
  l.append(a)
  if(max < a):
    max = a
    idx = i+1   
print(max)
print(idx)