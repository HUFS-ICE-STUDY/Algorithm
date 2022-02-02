n = int(input())
arr = list(map(int,input().split()))
dp = [10000]*n

if n == 1:
    print(0)
    exit()

if arr[0] <= 0:
    print(-1)
    exit()

for i in range(min(n-1,arr[0])):
    if dp[n-1] != 10000:
        print(1)
        exit()
    dp[i+1] = 1

for j in range(1,n-1):
    for k in range(1, min(arr[j]+1, n-1)):
        if dp[n-1] != 10000:
            break
        if j+k > n-1:
            continue
        dp[j+k] = min(dp[j]+1, dp[j+k])

if dp[n-1] == 10000:
    print(-1)
else:
    print(dp[n-1])