import sys

input = sys.stdin.readline

n, m = map(int, input().split())

males = list(map(int, input().split()))
females = list(map(int, input().split()))

males.sort()
females.sort()

# 사람수가 작은쪽은 남자라고 생각한다
if(n > m):
    males, females = females, males
    n, m = m, n

# dp[i][j] -> i번 남자와 j번 여자가 커플이 되었을 때까지 성격 차이의 최소 합
dp = [[sys.maxsize]*m for _ in range(n)]

# 정렬을 해준 배열이기 때문에 i번째 남자는 i번째 여자부터 i+m-n번째 여자 중에서만 짝을 만들어야
# 최대한 많은 커플을 만들 수 있다.
for i in range(n):
    for j in range(i, i+m-n+1):
        if(i == 0):
            if(j == 0):
                dp[i][j] = abs(males[i]-females[j])
            else:
                # i가 0번째 남자인 경우에는 이전의 사람과 커플이 된 경우와 현재 j번 여자와 커플이 된 경우중 최소값을 넣어준다.
                dp[i][j] = min(dp[i][j-1], abs(males[i]-females[j]))
        else:
            # i가 0번째 다음 남자인 경우에는 dp[i-1][j-1]인 최소합에서 j번째 여자와 커플이 된 경우와
            # j-1번째 여자와 커플이 된 경우중에 최소값을 넣어준다.
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(males[i]-females[j]))

print(dp[n-1][m-1])
