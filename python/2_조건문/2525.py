a, b = map(int, input().split())
c = int(input())

h = int(c/60)
m = c%60

if(b + m < 60):
  if(a+h < 24):
    print(a + h, b + m)
  else:
    print(a+h-24, b + m)
else:
  if(a+h < 23):
    print(a+h+1, b+m-60)
  else:
    print(a+h-23, b+m-60)