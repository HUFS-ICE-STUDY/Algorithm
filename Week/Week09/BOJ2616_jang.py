n = int(input())
arr = list(map(int,input().split()))
m = int(input())

pre_sum = [0]*(n+1)
for i in range(n):
    pre_sum[i+1] = pre_sum[i]+arr[i]

dp = [[0]*(n+1) for _ in range(4)]

for i in range(1,4):
    for j in range(m*i,n+1):
        dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + pre_sum[j]-pre_sum[j-m])
        
print(dp[3][n])