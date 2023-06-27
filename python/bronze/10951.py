import sys

"""from sqlalchemy import null"""
input = sys.stdin.readline
numlist = []

while True:
  try:
    a,b = map(int, input().split())
    numlist.append(a+b)
  except:
    break

for i in range(numlist.__len__()):
  print(numlist[i])