import sys
input = sys.stdin.readline

a = input()
length = len(a)-1
l = []
result = 1
for i in range(length):
  l.append(a[i])
for i in range(int(length / 2)):
  if(l[i] == l[length - i - 1]):
    continue
  else:
    result = 0
print(result)