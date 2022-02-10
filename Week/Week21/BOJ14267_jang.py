n,m = map(int,input().split())

arr = [[] for _ in range(n+1)]
connection = list(map(int,input().split()))
for i in range(1,n):
    arr[i+1].append(connection[i])

compliment = [0]*(n+1)

for _ in range(m):
    a,b = map(int,input().split())
    compliment[a] += b

for i in range(1,n+1):
    if arr[i]:
        for person in arr[i]:
            compliment[i] += compliment[person]
    print(compliment[i], end=' ')
