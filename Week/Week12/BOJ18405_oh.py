import sys
import heapq
import copy

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < n and 0 <= x < n and not examiner[y][x]):
        return True
    return False


n, k = map(int, input().split())

examiner = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())
queue = []

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

for i in range(n):
    for j in range(n):
        if(examiner[i][j]):
            heapq.heappush(queue, (examiner[i][j], i, j))

for _ in range(s):
    temp = []

    while(queue):
        virus, cy, cx = heapq.heappop(queue)

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]

            if(pos(ny, nx)):
                examiner[ny][nx] = virus
                heapq.heappush(temp, (virus, ny, nx))

    queue = copy.deepcopy(temp)

print(examiner[x-1][y-1])
