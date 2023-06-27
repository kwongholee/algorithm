import sys
input = sys.stdin.readline

a = int(input())
b = input()
l = []
for i in range(a):
  l.append(int(b[i]))
total = 0
for i in l:
  total += i
print(total)