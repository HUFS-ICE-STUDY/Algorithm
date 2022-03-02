import sys
import copy
import heapq

input = sys.stdin.readline

# 배열을 벗어나는가 판단


def pos(y, x):
    if(0 <= y < r and 0 <= x < c):
        return True
    return False

# 상어가 움직여서 어느 위치로 가고 어느 방향을 보고있는지 return
# 1칸씩 움직이지 않고, 알아낸 규칙을 통해서 한 번에 어디로 도착하는지, 어떤 방향을 보고있는지 찾아낸다.
# -> 시간단축


def move(y, x, s, d):
    if(d == 1):
        change = abs((y-s) // (r-1))
        y = (y-s) % (r*2 - 2)
    elif(d == 2):
        change = abs((y+s) // (r-1))
        y = (y+s) % (r*2 - 2)
    elif(d == 3):
        change = abs((x+s) // (c-1))
        x = (x+s) % (c*2 - 2)
    else:
        change = abs((x-s) // (c-1))
        x = (x-s) % (c*2 - 2)

    if(y >= r):
        y = 2*(r-1) - y
    if(x >= c):
        x = 2*(c-1) - x

    # 방향 바뀐횟수가 홀수인 경우에 방향을 반대로 바라보게 된다.
    if(change % 2):
        if(d == 1 or d == 3):
            d += 1
        else:
            d -= 1

    return y, x, d


r, c, m = map(int, input().split())
# sharks[i] -> i열에있는 상어를 행, 상어의 크기의 역순으로 heap큐에 넣어준다
sharks = [[] for _ in range(c)]

result = 0

for _ in range(m):
    sr, sc, s, d, z = map(int, input().split())

    heapq.heappush(sharks[sc-1], (sr-1, -z, s, d))

# 방향에 따른 움직임
move_to = {1: (-1, 0), 2: (1, 0), 3: (0, 1), 4: (0, -1)}

for i in range(c):
    # 1초뒤에 상어가 어디로 이동해있는지 임시로 저장하는 list
    temp_sharks = [[] for _ in range(c)]
    # 같은 자리에있는 상어가 움직인 경우에는 먼저 움직인 상어의 크기가 큰 경우이기 때문에 해당위치의 visit가 True라면 나머지는 잡아먹힌 상어이다.
    visit = [[False]*c for _ in range(r)]

    # 해당 열에 상어가 있는 경우에만 상어를 잡을 수 있다.
    if(sharks[i]):
        # 가장 가까이있는 상어 한 마리를 잡는다.
        visit[sharks[i][0][0]][i] = True
        result += -sharks[i][0][1]
        heapq.heappop(sharks[i])

    # 상어가 이동한다.
    for x in range(c):
        while(sharks[x]):
            y, z, s, d = heapq.heappop(sharks[x])

            if(visit[y][x]):
                continue

            ny, nx, nd = move(y, x, s, d)
            heapq.heappush(temp_sharks[nx], (ny, z, s, nd))
            visit[y][x] = True

    sharks = copy.deepcopy(temp_sharks)

print(result)
