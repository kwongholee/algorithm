import sys
input = sys.stdin.readline

a, b = input().split()
l = [a,b]
l2 = []
for i in l:
  t = i[2] + i[1] + i[0]
  i = int(t)
  l2.append(i)
print(max(l2[0], l2[1]))