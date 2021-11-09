import sys

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < r and 0 <= x < c):
        return True
    return False


r, c = map(int, input().split())

m = [list(input().rstrip()) for _ in range(r)]
island = []

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

for y in range(r):
    for x in range(c):
        if(m[y][x] == 'X'):
            cnt = 0
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]

                if(pos(ny, nx)):
                    if(m[ny][nx] == '.'):
                        cnt += 1
                else:
                    cnt += 1

            if(cnt < 3):
                island.append((y, x))

min_y, min_x, max_y, max_x = sys.maxsize, sys.maxsize, 0, 0

for y, x in island:
    min_y = min(min_y, y)
    min_x = min(min_x, x)
    max_y = max(max_y, y)
    max_x = max(max_x, x)

new_y = max_y - min_y + 1
new_x = max_x - min_x + 1

result = [['.']*(new_x) for _ in range(new_y)]

for y, x in island:
    ny = y - min_y
    nx = x - min_x

    result[ny][nx] = 'X'

for i in range(new_y):
    print(''.join(result[i]))
