from lib2to3.pgen2 import grammar
import sys
input = sys.stdin.readline
r,c,m = map(int,input().split())
# 북, 남, 동, 서
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

arr = [[[] for _ in range(c)] for _ in range(r)]

# (x, y)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기
for _ in range(m):
    x,y,s,d,z = map(int,input().split())
    arr[x-1][y-1].append([z,s,d-1])

def move():
    global arr
    temp = [[[] for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if arr[i][j]:
                x,y = i,j
                z,s,d = arr[i][j][0]
                shark = s
                while shark > 0:
                    nx = x + dx[d]
                    ny = y + dy[d]
                    if nx < 0 or nx >= r or ny < 0 or ny >= c:
                        if d == 0 or d == 2:    # 북,동 -> 남,서
                            d += 1
                        elif d == 1 or d == 3:    # 남,서 -> 북,동
                            d -= 1
                        continue
                    else:
                        x,y = nx,ny
                        shark -= 1
                temp[x][y].append([z,s,d])
    arr = temp[:]

score = 0

for j in range(c):
    # 상어잡기
    for i in range(r):
        if arr[i][j]:
            near_shark = arr[i][j][0]
            score += near_shark[0]
            arr[i][j].remove(near_shark)
            break
    # 상어무빙
    move()

    # 점심시간
    for a in range(r):
        for b in range(c):
            if len(arr[a][b]) >= 2:
                arr[a][b].sort(reverse=True)
                while len(arr[a][b]) >= 2:
                    arr[a][b].pop()

print(score)