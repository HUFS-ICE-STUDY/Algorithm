
dp = [0]*(1000001)
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in range(4,1000001):
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
n=int(input())
for item in range(n):
    print(dp[int(input())]%1000000009)
