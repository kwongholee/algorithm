import sys
input = sys.stdin.readline

a, b = map(int, input().split())
l = list(map(int, input().split()))
for i in l:
  if(b>i):
    print(i, end=" ")