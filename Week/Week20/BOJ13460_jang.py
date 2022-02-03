from collections import deque

n,m = map(int,input().split())
board = []

for i in range(n):
    board.append(list(input()))
    for j in range(m):
        if board[i][j] == 'R':
            rx = i
            ry = j
        elif board[i][j] == 'B':
            bx = i
            by = j

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(rx,ry,bx,by):
    queue = deque()
    queue.append((rx,ry,bx,by))
    visited = []
    visited.append((rx,ry,bx,by))
    count = 0
    
    while queue:
        for _ in range(len(queue)):
            rx, ry, bx, by = queue.popleft()
            if count > 10:
                return -1
            if board[rx][ry] == 'O':
                return count
            for i in range(4):

                # 빨간 구슬
                nrx, nry = rx, ry
                while True:
                    nrx += dx[i]
                    nry += dy[i]
                    if board[nrx][nry] == '#':
                        nrx -= dx[i]
                        nry -= dy[i]
                        break
                    if board[nrx][nry] == 'O':
                        break
                
                # 파란 구슬
                nbx, nby = bx, by
                while True:
                    nbx += dx[i]
                    nby += dy[i]
                    if board[nbx][nby] == '#':
                        nbx -= dx[i]
                        nby -= dy[i]
                        break
                    if board[nbx][nby] == 'O':
                        break

                # 파란 구슬이 구멍에 들어가는 경우는 제외
                if board[nbx][nby] == 'O':
                    continue

                # 두 구슬의 위치가 같은 경우 겹치지 않게 수정(맨하탄 거리가 큰 쪽이 겹쳐진 구슬)
                if nrx == nbx and nry == nby:
                    if abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by):
                        nrx -= dx[i]
                        nry -= dy[i]
                    else:
                        nbx -= dx[i]
                        nby -= dy[i]
                
                # 방문한 적이 없는 경우 큐에 추가
                if (nrx, nry, nbx, nby) not in visited:
                    queue.append((nrx, nry, nbx, nby))
                    visited.append((nrx, nry, nbx, nby))
        count += 1
    return -1

print(bfs(rx, ry, bx, by))