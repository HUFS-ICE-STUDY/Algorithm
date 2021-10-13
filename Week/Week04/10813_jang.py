n,m = map(int,input().split())

arr = []
for i in range(1,n+1):
    arr.append(i)

for j in range(m):
    b,f = map(int,input().split())
    arr[b-1],arr[f-1] = arr[f-1],arr[b-1]

print(*arr)