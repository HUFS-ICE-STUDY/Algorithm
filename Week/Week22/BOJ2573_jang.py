from collections import deque
import queue

n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

queue = deque()
year = 0
check = False

def bfs(a,b):
    queue.append((a,b))
    while queue:
        x,y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if arr[nx][ny] != 0 and visited[nx][ny] == False:
                visited[nx][ny] = True
                queue.append((nx,ny))
            elif arr[nx][ny] == 0:
                count[x][y] += 1

while True:
    visited = [[False]*m for _ in range(n)]
    count = [[0]*m for _ in range(n)]
    result = 0
    for i in range(1,n-1):
        for j in range(1,m-1):
            if arr[i][j] != 0 and visited[i][j] == False:
                result += 1
                bfs(i,j)
    # 빙산 깎기        
    for i in range(1,n-1):
        for j in range(1,m-1):
            arr[i][j] -= count[i][j]
            if arr[i][j] < 0:
                arr[i][j] = 0
    
    if result != 1:
        break
    year += 1

if result > 1:
    print(year)
else:
    print(0)