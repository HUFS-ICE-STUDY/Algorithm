import sys

input = sys.stdin.readline


def Find(x):
    if(parent[x] < 0):
        return x
    else:
        y = Find(Find(parent[x]))
        parent[x] = y
        return y


def Union(x, y):
    x_parent = Find(x)
    y_parent = Find(y)
    if(x_parent != y_parent):
        parent[y_parent] = x_parent


n = int(input())
m = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
route = list(map(int, input().split()))

parent = [-1]*(n+1)

for i in range(n):
    for j in range(i+1, n):
        if(arr[i][j]):
            Union(i+1, j+1)

root = Find(route[0])

for i in range(1, m):
    if(Find(route[i]) != root):
        print('NO')
        exit()

print('YES')
