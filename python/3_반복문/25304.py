totalPrice = int(input())
totalNum = int(input())
result = 0
for i in range(0,totalNum):
  price, num = map(int, input().split())
  result += price * num
if(result == totalPrice):
  print("Yes")
else:
  print("No")