import sys
input = sys.stdin.readline
#대소문자 구별하래요;;
a = input()
l = []
idx = -1
max = 0
for i in range(len(a)-1):
  if(i == 0):
    l.append([a[i],1])
  else:
    for j in range(len(l)):
      if(l[j][0] == a[i]):
        l[j][1] += 1
        break
      if(j == len(l)-1):
        l.append([a[i],1])
for i in range(len(l)):
  if(max < l[i][1]):
    max = l[i][1]
    idx = i
if(len(a)-1 != 1):
  for i in range(len(l)):
    if(max == l[i][1]):
      idx = -1
if(idx == -1):
  print('?')
else:
  print(a[idx].capitalize())