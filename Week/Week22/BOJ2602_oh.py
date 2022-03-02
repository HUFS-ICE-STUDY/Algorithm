import sys
import copy

input = sys.stdin.readline

s = input().rstrip()
angel = input().rstrip()
devil = input().rstrip()

# dp[i][j] -> i -> 0: angel, 1: devil, j -> s문자열에서 j번째 문자까지 완성이 가능한 경우의 수
dp = [[0]*len(s) for _ in range(2)]

for i in range(len(angel)):
    temp_dp = copy.deepcopy(dp)
    for j in range(len(s)):
        if(angel[i] == s[j]):
            if(j == 0):
                dp[0][j] += 1
            else:
                dp[0][j] += temp_dp[1][j-1]

        if(devil[i] == s[j]):
            if(j == 0):
                dp[1][j] += 1
            else:
                dp[1][j] += temp_dp[0][j-1]

print(dp[0][-1]+dp[1][-1])
