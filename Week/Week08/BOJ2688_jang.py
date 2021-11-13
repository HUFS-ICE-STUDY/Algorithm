import sys
input = sys.stdin.readline

dp = [[1,0,0,0,0,0,0,0,0,0] for _ in range(64)]
dp[0] = [1,1,1,1,1,1,1,1,1,1]
for i in range(1,64):
    for j in range(1,10):
        dp[i][j] = dp[i][j-1] + dp[i-1][j]

n = int(input())
for i in range(n):
    print(sum(dp[int(input())-1]))