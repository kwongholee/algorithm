import sys
input = sys.stdin.readline

a = int(input())
l = list(map(int, input().split()))
max = l[0]
min = l[0]
for i in l:
  if(max < i):
    max = i
  if(min > i):
    min = i
print(min, max)