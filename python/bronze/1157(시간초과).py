import sys
input = sys.stdin.readline

a = input().upper()
if (len(a)-1 == 1):
  print(a)
else:
  l=[]
  maxIdx = 0
  for i in range(len(a)-1):  
    if(i == 0):
      l.append([a[i], 1])
    else:
      for j in range(len(l)):
        if(l[j][0] == a[i]):
          l[j][1] += 1
          break
        else:
          l.append([a[i], 1])
  for i in range(len(l)):
    if(l[maxIdx][1] <= l[i][1]):
      maxIdx = i
  for i in range(maxIdx):
    if(l[maxIdx][1] == l[i][1]):
      maxIdx = -1
      break
  if(maxIdx == -1):
    print('?')
  else:
    print(l[maxIdx][0])