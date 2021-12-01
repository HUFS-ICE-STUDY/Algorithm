n,a,b = map(int,input().split())
print(n,a,b)
a -= 1
b -= 1
count = 0
while True:
    a = a//2
    b = b//2
    count += 1
    if a==b:
        print(count)
        break
