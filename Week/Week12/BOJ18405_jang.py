from collections import deque

n,k = map(int,input().split())
examiner = []
virus = []

for i in range(n):
    examiner.append(list(map(int,input().split())))
    for j in range(n):
        if examiner[i][j] != 0:
            # 바이러스의 값, x, y, 시간(0)
            virus.append((examiner[i][j], i, j,0))

s,ans_x,ans_y = map(int,input().split())
# 상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

virus.sort()
queue = deque(virus)

while queue:
    v,x,y,time = queue.popleft()
    if time == s:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<n:
            if examiner[nx][ny] == 0:
                examiner[nx][ny] = v
                queue.append((v,nx,ny,time+1))

print(examiner[ans_x-1][ans_y-1])