# 그래프 이론, 스패닝 트리
import sys

input = sys.stdin.readline


def Find(x):
    if(parent[x] == x):
        return x

    parent[x] = Find(parent[x])
    return parent[x]


def Union(x, y):
    x = Find(x)
    y = Find(y)

    if(x > y):
        parent[x] = y
    else:
        parent[y] = x


v, e = map(int, input().split())

arr = []
parent = [i for i in range(v+1)]
result = 0

for _ in range(e):
    s, e, w = map(int, input().split())

    arr.append([w, s, e])

arr.sort()

for i in arr:
    if(Find(i[1]) == Find(i[2])):
        continue

    result += i[0]
    Union(i[1], i[2])

print(result)
