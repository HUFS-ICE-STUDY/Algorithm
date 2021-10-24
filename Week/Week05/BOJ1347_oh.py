import sys

input = sys.stdin.readline

n = int(input())
s = input().rstrip()

direction = {0: (1, 0), 1: (0, -1), 2: (-1, 0), 3: (0, 1)}
cur = 0
route = [(0, 0)]
y, x = 0, 0
max_y, max_x, min_y, min_x = 0, 0, 0, 0

for c in s:
    dy = direction[cur][0]
    dx = direction[cur][1]

    if(c == 'F'):
        y += dy
        x += dx
        max_y = max(y, max_y)
        max_x = max(x, max_x)
        min_y = min(y, min_y)
        min_x = min(x, min_x)
        route.append((y, x))
    elif(c == 'R'):
        cur = (cur+1) % 4
    else:
        cur = (cur-1) % 4

size_y = max_y-min_y+1
size_x = max_x-min_x+1
arr = [['#']*size_x for _ in range(size_y)]

for i in route:
    y, x = i[0]-min_y, i[1]-min_x
    arr[y][x] = '.'

for i in range(size_y):
    print(''.join(arr[i]))
