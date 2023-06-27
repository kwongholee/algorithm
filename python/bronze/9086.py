import sys
input = sys.stdin.readline

a = int(input())
for i in range(a):
  b = input()
  print(b[0], end="")
  print(b[len(b)-2])   