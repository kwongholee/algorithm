import sys
input = sys.stdin.readline

a = int(input())
for i in range(0,a):
  b,c = map(int, input().split())
  print("Case #{0}: {1} + {2} = {3}".format(i+1,b,c, b+c))