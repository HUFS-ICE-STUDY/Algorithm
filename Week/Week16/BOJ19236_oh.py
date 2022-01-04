import sys
import copy

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < 4 and 0 <= x < 8):
        return True
    return False


def move(arr, shark):
    loc = [[-1, -1] for _ in range(16)]

    for i in range(4):
        for j in range(0, 8, 2):
            if(arr[i][j] != -1):
                loc[arr[i][j]-1] = [i, j]

    for idx in range(16):
        y, x = loc[idx]
        if(y != -1 and x != -1):
            d = arr[y][x+1] - 1
            for i in range(8):
                nd = (d + i) % 8
                ny = y + direction[nd][0]
                nx = x + direction[nd][1]
                if(pos(ny, nx) and not(ny == shark[0] and nx == shark[1])):
                    if(arr[ny][nx] != -1):
                        nidx = arr[ny][nx]-1
                        loc[idx], loc[nidx] = loc[nidx], loc[idx]
                    else:
                        loc[idx] = [ny, nx]
                    arr[ny][nx], arr[y][x] = arr[y][x], arr[ny][nx]
                    arr[ny][nx+1], arr[y][x+1] = nd+1, arr[ny][nx+1]
                    break

    return arr


def solution(arr, shark, cnt):
    global result

    y, x, d = shark
    arr[y][x], arr[y][x+1] = -1, -1

    arr = move(arr, shark)
    result = max(result, cnt)
    i = 1

    while(1):
        ny = y + (direction[d][0])*i
        nx = x + (direction[d][1])*i

        if(not pos(ny, nx)):
            break

        if(arr[ny][nx] != -1):
            next_shark = (ny, nx, arr[ny][nx+1]-1)
            arr_copy = copy.deepcopy(arr)
            solution(arr_copy, next_shark, cnt+arr[ny][nx])

        i += 1


fishes = [list(map(int, input().split())) for _ in range(4)]

direction = {0: (-1, 0), 1: (-1, -2), 2: (0, -2), 3: (1, -2),
             4: (1, 0), 5: (1, 2), 6: (0, 2), 7: (-1, 2)}

result = fishes[0][0]-1
shark = (0, 0, fishes[0][1]-1)
fishes_copy = copy.deepcopy(fishes)

solution(fishes_copy, shark, fishes[0][0])

print(result)
