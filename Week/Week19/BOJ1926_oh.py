import sys

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < n and 0 <= x < m and paper[y][x]):
        return True
    return False


n, m = map(int, input().split())

paper = [list(map(int, input().split())) for _ in range(n)]

visit = [[False]*m for _ in range(n)]
result = 0
result_cnt = 0

dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

for i in range(n):
    for j in range(m):
        if(paper[i][j] and not visit[i][j]):
            queue = [(i, j)]
            visit[i][j] = True
            cnt = 1

            while(queue):
                y, x = queue.pop(0)

                for k in range(4):
                    ny = y + dy[k]
                    nx = x + dx[k]

                    if(pos(ny, nx) and not visit[ny][nx]):
                        queue.append((ny, nx))
                        visit[ny][nx] = True
                        cnt += 1

            result = max(result, cnt)
            result_cnt += 1

print(result_cnt)
print(result)
