import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

dp = [sys.maxsize]*n
dp[0] = 0

for i in range(n):
    cur = dp[i]
    for j in range(1, arr[i]+1):
        if(i+j >= n):
            break

        if(cur+1 < dp[i+j]):
            dp[i+j] = cur+1

if(dp[n-1] == sys.maxsize):
    print(-1)
else:
    print(dp[n-1])
