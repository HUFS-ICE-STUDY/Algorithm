import sys

input = sys.stdin.readline


def solution(i, max_cnt, cnt):
    global result
    if(cnt == max_cnt):
        if(go_end()):
            result = min(result, cnt)
        return

    for num in range(i, (n-1)*h):
        r = num // (n-1)
        c = num % (n-1)
        if(c == 0 and able[r][c] and able[r][c+1]):
            able[r][c] = False
            solution(num+1, max_cnt, cnt+1)
            able[r][c] = True
        elif(able[r][c] and able[r][c-1] and able[r][c+1]):
            able[r][c] = False
            solution(num+1, max_cnt, cnt+1)
            able[r][c] = True


def go_end():
    temp = [i for i in range(n)]

    for i in range(h):
        for j in range(n):
            if(not able[i][j]):
                temp[j], temp[j+1] = temp[j+1], temp[j]

    for i in range(n):
        if(temp[i] != i):
            return False

    return True


n, m, h = map(int, input().split())

rows = [list(map(int, input().split())) for _ in range(m)]
able = [[True]*n for _ in range(h)]
row = [[False]*n for _ in range(h)]
result = sys.maxsize

for r, c in rows:
    able[r-1][c-1] = False

for i in range(4):
    solution(0, i, 0)

if(result == sys.maxsize):
    print(-1)
else:
    print(result)
