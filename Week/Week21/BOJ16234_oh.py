import sys
from collections import deque

input = sys.stdin.readline

# 좌표가 배열을 벗어나는지 판단


def pos(y, x):
    if(0 <= y < n and 0 <= x < n):
        return True
    return False

# 해당 좌표에서 연합 국가들을 찾아냄


def make_team(y, x):
    dq = deque([(y, x)])
    temp = [(y, x)]
    total = countries[y][x]
    visit[y][x] = True
    cnt = 1

    while(dq):
        cy, cx = dq.popleft()

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if(pos(ny, nx)):
                diff = abs(countries[cy][cx] - countries[ny][nx])

                if(not visit[ny][nx] and l <= diff <= r):
                    visit[ny][nx] = True
                    total += countries[ny][nx]
                    cnt += 1
                    dq.append((ny, nx))
                    temp.append((ny, nx))

    return cnt, total, temp


n, l, r = map(int, input().split())

countries = [list(map(int, input().split())) for _ in range(n)]
result = 0

dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

while(1):
    visit = [[False]*n for _ in range(n)]
    move = False

    for y in range(n):
        for x in range(n):
            if(not visit[y][x]):
                cnt, total, team = make_team(y, x)
                people = total // cnt
                # 연합국이 없는경우
                if(cnt == 1):
                    continue

                for ty, tx in team:
                    countries[ty][tx] = people
                # 인구이동이 발생한 날인 경우
                move = True
    # 인구이동이 일어나지 않았으면 빠져나가준다.
    if(not move):
        break

    result += 1

print(result)
