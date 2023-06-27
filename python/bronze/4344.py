import sys
input = sys.stdin.readline

a = int(input())
l = []
for i in range(a):
  l2 = list(map(int, input().split()))
  l.append(l2)
for i in range(len(l)):
  total = 0
  person = 0
  for j in range(1,len(l[i])):
    total += l[i][j]
  average = total / l[i][0]
  for j in range(1, len(l[i])):
    if(l[i][j] > average):
      person += 1
  print(l[i][0] / person * 10, end="")
  print("%") 