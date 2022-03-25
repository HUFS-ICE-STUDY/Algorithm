from copy import deepcopy

# 뿌요가 4개 이상인지 체크
def dfs_check(x,y,color,cnt):
    arr2[x][y] = 'O'
    for dx,dy in direction:
        nx = x+dx
        ny = y+dy
        if (0 <= nx < 12) and (0 <= ny < 6) and arr2[nx][ny] == color:
            cnt = dfs_check(nx,ny,color,cnt+1)
    return cnt

def dfs(x,y,color):
    arr1[x][y] = 'O'
    for dx,dy in direction:
        nx = x+dx
        ny = y+dy
        if (0 <= nx < 12) and (0 <= ny < 6) and arr1[nx][ny] == color:
            dfs(nx,ny,color)

def update():
    for j in range(6):
        for i in range(12):
            if arr1[i][j] == 'O':
                up = arr1[0][j]
                for k in range(i):
                    down = arr1[k+1][j]
                    arr1[k+1][j] = up
                    up = down
                arr1[0][j] = '.'

graph = [list(input()) for _ in range(12)]
arr1 = deepcopy(graph)
direction = [(-1,0), (1,0), (0,-1), (0,1)]
combo = 0
while True:
    arr2 = deepcopy(arr1)
    check = 0
    for i in range(12):
        for j in range(6):
            if arr1[i][j] in 'RGBPY':
                if dfs_check(i,j,arr1[i][j],1) >= 4:
                    dfs(i,j,arr1[i][j])
                    check = 1
    update()
    if check == 0:
        break
    combo += 1
print(combo)
