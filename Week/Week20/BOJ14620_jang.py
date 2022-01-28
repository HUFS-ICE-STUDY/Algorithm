n = int(input())
flower_bed = [list(map(int,input().split())) for _ in range(n)]
directions = [(0,0), (0,1), (0,-1), (1,0), (-1,0)]  # 가운데랑 4방향
ans = 99999
def land_price(f1,f2,f3):
    ret = 0
    check = []

    for flower in [f1,f2,f3]:
        x = flower // n
        y = flower % n
        
        if x == 0 or x == n-1 or y == 0 or y == n-1:
            return 99999
        for dx,dy in directions:
            nx = x+dx
            ny = y+dy
            ret += flower_bed[nx][ny]
            check.append((nx,ny))

    if len(set(check)) != len(check): # 중복 체크
        return 99999
    
    return ret

for i in range(n+1,n*n):
    for j in range(i+2,n*n):
        for k in range(j+2,n*n):
            ans = min(ans,land_price(i,j,k))

print(ans)
