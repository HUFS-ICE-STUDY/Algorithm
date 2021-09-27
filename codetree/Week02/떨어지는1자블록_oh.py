import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

for i in range(1, n):
    for j in range(k-1, k+m-1):
        if(arr[i][j]):
            for idx in range(k-1, k+m-1):
                arr[i-1][idx] = 1

            for y in range(n):
                for x in range(n):
                    print(arr[y][x], end=' ')
                print()

            exit()

for idx in range(k-1, k+m-1):
    arr[n-1][idx] = 1

for y in range(n):
    for x in range(n):
        print(arr[y][x], end=' ')
    print()
