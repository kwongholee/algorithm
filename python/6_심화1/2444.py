import sys
input = sys.stdin.readline

n = int(input())
l = []

for i in range(1,2*n):
  if(i <= n):
    a = ' ' * (n-i) + '*'*(2*i-1)
    l.append(a)
  else:
    b = l[2*(n-1) - i +1]
    l.append(b)
  
for i in l:
  print(i)