import sys
input = sys.stdin.readline

l=[]
for i in range(1,31):
  l.append(i)
for i in range(28):
  a = int(input())
  l.remove(a)
for i in l:
  print(i)