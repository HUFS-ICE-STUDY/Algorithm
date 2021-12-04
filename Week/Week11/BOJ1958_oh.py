import sys

input = sys.stdin.readline

arr = [input().rstrip() for _ in range(3)]

dp = [[[0 for i in range(len(arr[0]) + 1)] for j in range(len(arr[1]) + 1)]
      for k in range(len(arr[2]) + 1)]

for k in range(1, len(arr[2]) + 1):
    for j in range(1, len(arr[1]) + 1):
        for i in range(1, len(arr[0]) + 1):
            if arr[0][i - 1] == arr[1][j - 1] == arr[2][k - 1]:
                dp[k][j][i] = dp[k - 1][j - 1][i - 1] + 1
            else:
                dp[k][j][i] = max(dp[k - 1][j][i], dp[k][j - 1][i], dp[k][j][i - 1],
                                  dp[k - 1][j - 1][i], dp[k][j - 1][i - 1], dp[k - 1][j][i - 1])

print(dp[-1][-1][-1])
