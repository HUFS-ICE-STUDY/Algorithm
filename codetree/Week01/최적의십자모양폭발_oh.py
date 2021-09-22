import sys
import copy

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < n and 0 <= x < n):
        return True
    return False


def bomb(r, c):
    temp = [[0]*n for _ in range(n)]

    if(pos(r, c)):
        cnt = arr[r][c]

        for i in range(cnt):
            if(pos(r-i, c)):
                arr[r-i][c] = 0

            if(pos(r, c-i)):
                arr[r][c-i] = 0

            if(pos(r+i, c)):
                arr[r+i][c] = 0

            if(pos(r, c+i)):
                arr[r][c+i] = 0
    else:
        print(0)
        exit()

    next = [n-1]*n

    for i in range(n-1, -1, -1):
        for j in range(n):
            if(arr[i][j]):
                temp[next[j]][j] = arr[i][j]
                next[j] -= 1

    return temp


def solution(temp):
    cnt = 0
    for i in range(n):
        for j in range(n):
            if(temp[i][j]):
                if(pos(i+1, j) and temp[i][j] == temp[i+1][j]):
                    cnt += 1

                if(pos(i, j+1) and temp[i][j] == temp[i][j+1]):
                    cnt += 1

    return cnt


n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
result = 0

for i in range(n):
    for j in range(n):
        temp = copy.deepcopy(arr)
        t = bomb(i, j)
        result = max(result, solution(t))
        arr = copy.deepcopy(temp)

print(result)
