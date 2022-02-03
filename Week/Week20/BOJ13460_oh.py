import sys
from collections import deque

# 판을 움직임


def move(y, x, i):
    cnt = 0

    while(1):
        ny = y + dy[i]
        nx = x + dx[i]

        if(board[ny][nx] == '#'):
            return y, x, cnt
        elif(board[ny][nx] == 'O'):
            return -1, -1, cnt+1
        else:
            y += dy[i]
            x += dx[i]
            cnt += 1


input = sys.stdin.readline

n, m = map(int, input().split())

board = [list(input().rstrip()) for _ in range(n)]

dq = deque()
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]
# visit[ry][rx][by][bx] -> 빨간 공이 (ry, rx), 파란 공이 (by,bx)를 방문했는지 저장하는 list
visit = [[[[False]*m for _ in range(n)] for _ in range(m)] for _ in range(n)]

# 최초의 빨간공의 위치와 파란공의 위치를 찾음
for y in range(n):
    for x in range(m):
        if(board[y][x] == 'R'):
            ry, rx = y, x

        if(board[y][x] == 'B'):
            by, bx = y, x

# deque로 bfs를 실행
dq.append((0, ry, rx, by, bx))

while(dq):
    cnt, ry, rx, by, bx = dq.popleft()

    if(cnt >= 10):
        break

    for i in range(4):
        nry, nrx, r_cnt = move(ry, rx, i)
        nby, nbx, b_cnt = move(by, bx, i)

        if(nby == -1 and nbx == -1):
            continue

        if(nry == -1 and nrx == -1):
            print(cnt+1)
            exit(0)

        if(nry == nby and nrx == nbx):
            if(r_cnt > b_cnt):
                nry -= dy[i]
                nrx -= dx[i]
            else:
                nby -= dy[i]
                nbx -= dx[i]

        if(not visit[nry][nrx][nby][nbx]):
            visit[nry][nrx][nby][nbx] = True
            dq.append((cnt+1, nry, nrx, nby, nbx))

print(-1)
