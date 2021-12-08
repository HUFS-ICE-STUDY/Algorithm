import sys

input = sys.stdin.readline

n, m = map(int, input().split())
chart = list(map(int, input().split()))
able = [[False]*1024 for _ in range(m+1)]

for i in chart:
    able[1][abs(i)] = True

for i in range(2, m+1):
    for j in range(1024):
        if(able[i-1][j]):
            for k in range(n):
                able[i][j ^ abs(chart[k])] = True

for i in range(1023, -1, -1):
    if(able[m][i]):
        print(i)
        exit(0)
