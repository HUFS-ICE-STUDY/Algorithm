n,m = map(int,input().split())
# dp[n][m] = 오름차순으로 정렬된 남자 n명, 여자 m명이 커플이 되는 최소값
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

arr1 = [0] + sorted(list(map(int,input().split())))
arr2 = [0] + sorted(list(map(int,input().split())))

for i in range(1,n+1):
    for j in range(1,m+1):
        dp[i][j] = dp[i-1][j-1] + abs(arr1[i] - arr2[j])

        if (i > j):
            dp[i][j] = min(dp[i][j], dp[i-1][j])

        elif (i < j):
            dp[i][j] = min(dp[i][j], dp[i][j-1])

print(dp[n][m])