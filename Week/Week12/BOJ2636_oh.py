import sys
import heapq

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < n and 0 <= x < m and not visit[y][x]):
        return True
    return False


n, m = map(int, input().split())

frame = [list(map(int, input().split())) for _ in range(n)]
result = 0
cnt = 0

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

while(1):
    visit = [[False]*m for _ in range(n)]
    queue = [(0, 0)]
    cheese = []

    while(queue):
        y, x = heapq.heappop(queue)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if(pos(ny, nx)):
                visit[ny][nx] = True
                if(frame[ny][nx]):
                    cheese.append((ny, nx))
                else:
                    heapq.heappush(queue, (ny, nx))

    for y, x in cheese:
        frame[y][x] = 0

    if(not len(cheese)):
        break
    else:
        result += 1
        cnt = len(cheese)

print(result)
print(cnt)
