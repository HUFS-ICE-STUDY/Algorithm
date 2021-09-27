import sys

input = sys.stdin.readline

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
next = [[[0, 0, 0, 0] for _ in range(n+2)] for _ in range(n+2)]
result = 0
x1, x2, y1, y2 = n, -1, n, -1


def pos(y, x):
    if(0 <= y < n and 0 <= x < n):
        return True
    return False


def change_direction(move, wall):
    if(move == 0):
        if(wall == 1):
            move = 3
        else:
            move = 1
    elif(move == 1):
        if(wall == 1):
            move = 2
        else:
            move = 0
    elif(move == 2):
        if(wall == 1):
            move = 1
        else:
            move = 3
    else:
        if(wall == 1):
            move = 0
        else:
            move = 2

    return move


def solution(y, x, move):
    cnt = 1

    while(pos(y, x)):
        if(arr[y][x]):
            move = change_direction(move, arr[y][x])

        cnt_plus = next[y][x][move]

        if(move == 0):
            x += cnt_plus
        elif(move == 1):
            y += cnt_plus
        elif(move == 2):
            x -= cnt_plus
        else:
            y -= cnt_plus

        cnt += cnt_plus

    return cnt


for i in range(n):
    cnt0 = 0
    cnt1 = 0
    cnt2 = 0
    cnt3 = 0
    for j in range(n):
        cnt0 += 1
        cnt1 += 1
        cnt2 += 1
        cnt3 += 1

        next[i][n-j-1][0] = cnt0
        next[n-j-1][i][1] = cnt1
        next[i][j][2] = cnt2
        next[j][i][3] = cnt3

        if(arr[i][n-j-1]):
            cnt0 = 0

        if(arr[n-j-1][i]):
            cnt1 = 0

        if(arr[i][j]):
            cnt2 = 0

        if(arr[j][i]):
            cnt3 = 0

for i in range(n):
    result = max(result, solution(0, i, 1), solution(i, 0, 0),
                 solution(n-1, i, 3), solution(i, n-1, 2))

print(result)
