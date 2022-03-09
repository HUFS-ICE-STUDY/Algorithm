import sys
from collections import deque
# 배열을 벗어나는지 판단하는 함수


def pos(y, x):
    if(0 <= y < n and 0 <= x < m):
        return True
    return False


input = sys.stdin.readline

n, m = map(int, input().split())

maze = [list(input().rstrip()) for _ in range(n)]
# 민식이가 움직이는 방향
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]
# 현재 위치를 찾아냄
for y in range(n):
    for x in range(m):
        if(maze[y][x] == '0'):
            cy, cx = y, x
# visit[y][x][keys] -> (y,x)에서 keys(2진수로 어떤 키를 가지고 있는지 판단)를 가진 상태로 방문한적이 있는지 저장하는 list
visit = [[[False]*64 for _ in range(m)] for _ in range(n)]

# bfs를 이용
dq = deque([(cy, cx, 0b000000, 0)])
visit[cy][cx][0] = True
result = -1

while(dq):
    y, x, keys, cnt = dq.popleft()
    # 출구인 경우
    if(maze[y][x] == '1'):
        result = cnt
        break
    # 키가 있는 위치인 경우
    if('a' <= maze[y][x] <= 'f'):
        keys |= (1 << ord(maze[y][x])-97)
    # 움직임
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        # 다음에 갈 위치가 배열을 벗어나지 않고, 벽이 아니고, keys를 가지고 방문한적이 없는 경우
        if(pos(ny, nx) and maze[ny][nx] != '#' and not visit[ny][nx][keys]):
            # 다음에 갈 위치가 열쇠가 필요한 문이 있고, 그 열쇠를 가지고 있는 경우
            if('A' <= maze[ny][nx] <= 'F' and not keys & (1 << ord(maze[ny][nx]) - 65)):
                continue
            visit[ny][nx][keys] = True
            dq.append((ny, nx, keys, cnt+1))

print(result)
