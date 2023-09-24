import sys
input = sys.stdin.readline

a = input()
i = 0
count = 0
while(i != len(a)-1):
    if(a[i:i+3] == 'dz='):
        count += 1
        i += 3
    elif(a[i:i+2] == 'c='):
        count += 1
        i += 2
    elif(a[i:i+2] == 'c-'):
        count += 1
        i += 2
    elif(a[i:i+2] == 'lj'):
        count += 1
        i += 2
    elif(a[i:i+2] == 'nj'):
        count += 1
        i += 2
    elif(a[i:i+2] == 's='):
        count += 1
        i += 2
    elif(a[i:i+2] == 'z='):
        count += 1
        i += 2
    else:
        count += 1
        i += 1
print(count)