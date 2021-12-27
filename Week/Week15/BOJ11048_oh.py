import sys


def possible(y, x):
    if(0 <= y < n and 0 <= x < m):
        return True
    return False


def max_candy(i, j):
    result = 0

    dx = [0, -1, -1]
    dy = [-1, 0, -1]

    for idx in range(3):
        y = i + dy[idx]
        x = j + dx[idx]

        if(possible(y, x)):
            result = max(result, arr[y][x])

    return result


n, m = map(int, sys.stdin.readline().split())
arr = []

for _ in range(n):
    row = list(map(int, sys.stdin.readline().split()))

    arr.append(row)

for i in range(n):
    for j in range(m):
        arr[i][j] += max_candy(i, j)

print(arr[n-1][m-1])
