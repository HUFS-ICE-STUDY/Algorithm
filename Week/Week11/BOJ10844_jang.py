n = int(input())
dp = [[0]*10 for _ in range(n)]
dp[0] = [0,1,1,1,1,1,1,1,1,1]

for i in range(1,n):
    for j in range(10):
        if j == 0:
            dp[i][0] = dp[i-1][1]
        elif j == 9:
            dp[i][9] = dp[i-1][8]
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[n-1])%10**9)


