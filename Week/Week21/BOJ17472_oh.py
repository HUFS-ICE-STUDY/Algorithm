import sys
import heapq

input = sys.stdin.readline

# 배열을 벗어나는지 판단


def pos(y, x):
    if(0 <= y < n and 0 <= x < m):
        return True
    return False

# 입력받은 배열에서 같은 섬끼리 list로 묶어서 islands 배열에 저장


def get_island(y, x):
    island = [(y, x)]
    queue = [(y, x)]
    visit[y][x] = True

    while(queue):
        y, x = queue.pop(0)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if(pos(ny, nx) and not visit[ny][nx] and arr[ny][nx]):
                visit[ny][nx] = True
                island.append((ny, nx))
                queue.append((ny, nx))

    return island

# bridge[i][j] -> i,j번째 섬을 연결해주는 다리의 최소 길이를 구해줌


def set_bridge(start, end):
    for y, x in islands[start]:
        for i in range(4):
            k = 1
            while(1):
                ny = y + dy[i]*k
                nx = x + dx[i]*k

                if(not pos(ny, nx) or (ny, nx) in islands[start]):
                    break

                if(arr[ny][nx]):
                    if(k <= 2 or not (ny, nx) in islands[end]):
                        break
                    else:
                        bridge[start][end] = min(bridge[start][end], k-1)
                        bridge[end][start] = min(bridge[end][start], k-1)
                        break

                k += 1


n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

# 입력받은 배열에서 섬을 추출
islands = []
visit = [[False]*m for _ in range(n)]

for y in range(n):
    for x in range(m):
        if(arr[y][x] and not visit[y][x]):
            islands.append(get_island(y, x))

# 추출한 섬에서 각 섬까지 다리의 최소 길이를 구함
islands_num = len(islands)
bridge = [[sys.maxsize]*islands_num for _ in range(islands_num)]

for i in range(islands_num):
    for j in range(i+1, islands_num):
        set_bridge(i, j)

# 최소 스패닝 트리를 이용해 모든 섬을 연결할 수 있는 다리들의 최소 길이를 구함
# Prim 알고리즘 사용
island_visit = [False]*(islands_num)
queue = [(0, 0)]
result = 0
cnt = 0

while(cnt < islands_num):
    if(not queue):
        result = -1
        break

    cost, node = heapq.heappop(queue)

    if(island_visit[node]):
        continue

    island_visit[node] = True
    result += cost
    cnt += 1

    for i in range(islands_num):
        if(not island_visit[i] and bridge[node][i] != sys.maxsize):
            heapq.heappush(queue, (bridge[node][i], i))

print(result)
