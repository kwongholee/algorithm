a,b,c = map(int, input().split())
if(a==b and a==c):
  print(10000 + a*1000)
elif(a==b or a==c):
  print(1000 + a*100)
elif(b==c):
  print(1000 + b*100)
else:
  max = a
  if(max<b):
    max = b
  if(max<c):
    max = c
  print(max*100)