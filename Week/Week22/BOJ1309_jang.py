"""
# Solution 1
n = int(input())

dp = [[0,0,0] for _ in range(n)]    

# dp[n][0] = n번째 열에 사자가 없는 경우
# dp[n][1] = n번째 열에 사자가 왼쪽에 있는 경우
# dp[n][2] = n번째 열에 사자가 오른쪽에 있는 경우

dp[0] = [1,1,1]

for i in range(1,n):
    dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901
    dp[i][1] = dp[i-1][0] + dp[i-1][2]             
    dp[i][2] = dp[i-1][0] + dp[i-1][1]

print(sum(dp[n-1])%9901)  # 오버플로우 방지를 위해 나누어준다.
"""

"""
# Solution 2
n = int(input())
dp = [0]*(n+1)
dp[0] = 3
dp[1] = 7
for i in range(2,n):
    dp[i] = (dp[i-2] + dp[i-1]*2)%9901
print(dp[n-1])
"""

# Solution 3
n = int(input())
a,b = 1,3
for i in range(n-1):
    a,b = b,(b*2+a)%9901
print(b)