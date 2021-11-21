import sys

input = sys.stdin.readline

n = int(input())

people = list(map(int, input().split()))

num = int(input())
dp = [[0]*3 for _ in range(n)]
dp[num-1][0] = sum(people[:num])

for i in range(num, n):
    group = sum(people[i-num+1:i+1])
    for j in range(3):
        if(j == 0):
            dp[i][j] = max(dp[i-1][0], group)
        elif(i > j*num):
            dp[i][j] = max(dp[i-1][j], dp[i-num][j-1] + group)

print(dp[n-1][2])
