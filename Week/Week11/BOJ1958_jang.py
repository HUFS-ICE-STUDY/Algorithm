s1 = input()
s2 = input()
s3 = input()

dp = [[[0]*(len(s1)+1) for a in range(len(s2)+1)] for b in range(len(s3)+1)]

for i in range(1, len(s3)+1):
    for j in range(1, len(s2)+1):
        for k in range(1, len(s1)+1):
            if s3[i-1] == s2[j-1] == s1[k-1]:
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1
            else:
                dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-1][k], dp[i-1][j][k])
    
print(dp[-1][-1][-1])
