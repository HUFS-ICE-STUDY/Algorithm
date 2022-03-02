import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

# 부하직원들에게 칭찬 값을 더해주는 깊이 우선 탐색


def dfs(i, w):
    result[i] += w

    # 부하가 없는경우에는 return
    if(not junior[i]):
        return

    for j in junior[i]:
        dfs(j, w)


n, m = map(int, input().split())
# 직속 상관이 누구인지 저장하는 list
supervisor = list(map(int, input().split()))
# 자신의 부하가 누구인지 저장하는 list
junior = [[] for _ in range(n)]
# 처음 m번의 입력받은 칭찬을 저장하는 list
temp = [0]*n
# 결과값을 저장하는 list
result = [0]*n

for i in range(n):
    # 상관이 없는 경우
    if(supervisor[i] == -1):
        continue

    junior[supervisor[i]-1].append(i)

for _ in range(m):
    i, w = map(int, input().split())

    temp[i-1] += w

for i in range(n):
    # 칭찬을 받은적 있는 경우에만 dfs를 돌아준다.
    if(temp[i]):
        dfs(i, temp[i])

print(*result)
