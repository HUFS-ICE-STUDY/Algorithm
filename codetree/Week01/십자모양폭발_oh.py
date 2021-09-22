import sys

input = sys.stdin.readline


def pos(y, x):
    if(0 <= y < n and 0 <= x < n):
        return True
    return False


n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
temp = [[0]*n for _ in range(n)]

r, c = map(int, input().split())

if(pos(r-1, c-1)):
    cnt = arr[r-1][c-1]

    for i in range(cnt):
        if(pos(r-i-1, c-1)):
            arr[r-i-1][c-1] = 0

        if(pos(r-1, c-i-1)):
            arr[r-1][c-i-1] = 0

        if(pos(r+i-1, c-1)):
            arr[r+i-1][c-1] = 0

        if(pos(r-1, c+i-1)):
            arr[r-1][c+i-1] = 0
else:
    print(0)
    exit()

next = [n-1]*n

for i in range(n-1, -1, -1):
    for j in range(n):
        if(arr[i][j]):
            temp[next[j]][j] = arr[i][j]
            next[j] -= 1

for i in range(n):
    for j in range(n):
        print(temp[i][j], end=' ')
    print()
