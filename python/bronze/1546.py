import sys
input = sys.stdin.readline

a = int(input())
l = list(map(int, input().split()))
total = 0
max = 0
for i in l:
  if(max < i):
    max = i
for i in l:
  i = (i/max)*100
  total += i
print(total/a)