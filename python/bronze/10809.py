import sys
input = sys.stdin.readline

a = input()
inputList = []
alphaList = []
for i in range(len(a)-1):
  inputList.append(a[i])
for i in range(26):
  alphaList.append(-1)
for i in range(len(inputList)):
  if(alphaList[ord(inputList[i])-97] == -1):
    alphaList[ord(inputList[i])-97] = i
for i in alphaList:
  print(i, end=" ")