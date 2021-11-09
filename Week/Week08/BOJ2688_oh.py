import sys

input = sys.stdin.readline

t = int(input())

num = 0
arr = []

for _ in range(t):
    n = int(input())
    arr.append(n)

    num = max(num, n)

dp = [[0]*10 for i in range(65)]
dp[1] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

for i in range(2, 65):
    dp[i][0] = 1
    for j in range(1, 10):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

for i in arr:
    print(sum(dp[i]))
