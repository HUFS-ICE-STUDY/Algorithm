import sys

input = sys.stdin.readline

t = int(input())

move = {0: (1, 0), 1: (0, 1), 2: (-1, 0), 3: (0, -1)}

for _ in range(t):
    s = input().rstrip()
    temp = set()
    temp.add((0, 0))
    cur = 0
    y = 0
    x = 0
    min_y, max_y, min_x, max_x = sys.maxsize, - \
        sys.maxsize, sys.maxsize, -sys.maxsize

    for c in s:
        if(c == 'F'):
            y += move[cur][0]
            x += move[cur][1]
        elif(c == 'B'):
            y -= move[cur][0]
            x -= move[cur][1]
        elif(c == 'L'):
            cur = (cur-1) % 4
        else:
            cur = (cur+1) % 4

        temp.add((y, x))

    for y, x in temp:
        min_y = min(y, min_y)
        max_y = max(y, max_y)
        min_x = min(x, min_x)
        max_x = max(x, max_x)

    print((max_y-min_y)*(max_x-min_x))
