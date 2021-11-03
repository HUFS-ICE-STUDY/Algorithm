import sys

input = sys.stdin.readline

n, l = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

result = 0
cur = 0

for i in arr:
    d, r, g = i

    result += (d - cur)

    if(result % (g+r) <= r):
        result += (r - result % (g+r))

    cur = d

result += (l - cur)

print(result)
