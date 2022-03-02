import sys
from collections import deque as dq


def pos(y, x):
    if(0 <= y < n and 0 <= x < m):
        return True
    return False


def decrease(y, x):
    cnt = 0

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if(pos(ny, nx) and ice[ny][nx] == 0):
            cnt += 1

    return cnt


def bfs(y, x):
    q = dq([(y, x)])
    visit[y][x] = True

    while(q):
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if(pos(ny, nx) and not visit[ny][nx] and ice[ny][nx]):
                q.append((ny, nx))
                visit[ny][nx] = True


n, m = map(int, sys.stdin.readline().split())

ice = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
result = 0

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

while(1):
    arr = [[0]*m for _ in range(n)]
    visit = [[False]*m for _ in range(n)]
    cnt = 0

    for i in range(n):
        for j in range(m):
            if(ice[i][j]):
                arr[i][j] = decrease(i, j)

    for i in range(n):
        for j in range(m):
            if(ice[i][j]):
                if(ice[i][j] < arr[i][j]):
                    ice[i][j] = 0
                else:
                    ice[i][j] -= arr[i][j]

    for i in range(n):
        for j in range(m):
            if(ice[i][j] and not visit[i][j]):
                bfs(i, j)
                cnt += 1

    result += 1

    if(cnt > 1):
        print(result)
        break
    elif(cnt == 0):
        print(0)
        break
