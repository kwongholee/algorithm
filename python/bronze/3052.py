import sys
input = sys.stdin.readline

l=[]
for i in range(10):
  a = int(input())
  a %= 42
  if(l.count(a) == 0):
    l.append(a)
print(len(l))