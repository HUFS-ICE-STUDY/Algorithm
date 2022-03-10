from collections import deque

n = int(input())
k = int(input())
apple = [list(map(int,input().split())) for _ in range(k)]
l = int(input())
move = {}
for i in range(l):
    x,c = input().split()
    move[int(x)] = c

directions = [(0,1),(1,0),(0,-1),(-1,0)] # 우,하,좌,상
map = [[0]*n for _ in range(n)]

for r,c in apple:
    map[r-1][c-1] = 1

d = 0
time = 0
baem = deque([(0,0)])
nx,ny = 0,0
while True:
    nx = nx + directions[d][0]
    ny = ny + directions[d][1]
    time += 1
    if nx<0 or ny<0 or nx>=n or ny>=n or (nx,ny) in baem:
        print(time)
        break
    
    if map[nx][ny] == 1:
        map[nx][ny] = 0
    else:
        baem.popleft()
        
    baem.append((nx,ny))

    if time in move.keys():
        if move[time] == 'L':
            d -= 1
        if move[time] == 'D':
            d += 1

        if d >= 4:
            d -= 4
        if d < 0:
            d += 4