import sys
input = sys.stdin.readline

a=input()
length = len(a)-1
total = 2 * length
for i in range(length):
  if(a[i] >= 'A' and a[i] <= 'C'):
    total+=1
  elif(a[i] >= 'D' and a[i] <= 'F'):
    total+=2
  elif(a[i] >= 'G' and a[i] <= 'I'):
    total+=3
  elif(a[i] >= 'J' and a[i] <= 'L'):
    total+=4
  elif(a[i] >= 'M' and a[i] <= 'O'):
    total+=5
  elif(a[i] >= 'P' and a[i] <= 'S'):
    total+=6
  elif(a[i] >= 'T' and a[i] <= 'V'):
    total+=7
  else:
    total+=8
print(total)