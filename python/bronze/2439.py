import sys
input = sys.stdin.readline

a = int(input())
for i in range(0,a):
  print(" "*(a-i-1)+"*"*(i+1))