n = int(input())

cf = n//5

for i in range(cf):
    if (n-cf*5)%2 == 0:
        break
    cf -= 1

if n == 1 or n == 3: print(-1)
else: print(cf+(n-cf*5)//2)