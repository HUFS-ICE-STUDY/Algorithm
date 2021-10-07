import sys
from collections import deque as dq
import heapq


def pos(y, x):
    if(0 <= y < n and 0 <= x < n and not visit[y][x]):
        return True
    return False


def solution(start, cur):
    global visit

    q = dq([start])

    y, x, cnt = start
    arr[y][x] = 0
    hq = []
    visit = [[False]*n for _ in range(n)]
    visit[y][x] = True

    while(q):
        y, x, cnt = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if(pos(ny, nx)):
                visit[ny][nx] = True

                if(arr[ny][nx] == 0 or arr[ny][nx] == cur):
                    q.append((ny, nx, cnt+1))
                elif(arr[ny][nx] < cur):
                    heapq.heappush(hq, (cnt+1, ny, nx))

    if(hq):
        return hq[0]
    return None


n = int(sys.stdin.readline())

arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if(arr[i][j] == 9):
            start = (i, j, 0)

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

time = 0
cur = 2
eat = 0

while(1):
    shark = solution(start, cur)

    if(not shark):
        break

    cnt, y, x = shark
    time += cnt
    eat += 1

    if(eat == cur):
        cur += 1
        eat = 0

    start = (y, x, 0)

print(time)
