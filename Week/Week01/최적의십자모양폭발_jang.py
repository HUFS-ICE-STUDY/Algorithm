# branch test by Jang
# 변수 선언 및 입력:
n = int(input())    
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

# 배열 범위 확인
def in_range(x,y):
    if(0<=x<n and 0<=y<n): return True
    return False

# 동일한 쌍의 수를 찾기
def count_pair(arr):
    count = 0
    # 가로 방향으로 체크
    for i in range(n):
        for j in range(1,n):
            if arr[i][j] == 0 or arr[i][j-1] == 0:
                continue
            if arr[i][j-1] == arr[i][j]:
                count += 1
    # 세로 방향으로 체크
    for i in range(n):
        for j in range(1,n):
            if arr[j-1][i] == 0 or arr[j][i] == 0:
                continue
            if arr[j-1][i] == arr[j][i]:
                count += 1
    return count

def best_boom(x,y,arr):
    b = [item[:] for item in arr]
    count = b[x][y]

    # 폭탄 범위 만큼 0으로 만든다
    for i in range(count):
        if(in_range(x-i, y)):
            b[x-i][y] = 0
        if(in_range(x+i, y)):
            b[x+i][y] = 0
        if(in_range(x, y-i)):
            b[x][y-i] = 0
        if(in_range(x, y+i)):
            b[x][y+i] = 0  

    ans = [[0]*n for _ in range(n)]

    # 폭탄을 터지고 중력이 작용
    for i in range(n):
        temp = n-1
        for j in range(n):
            if b[n-1-j][i]:
                ans[temp][i] = b[n-1-j][i]
                temp -= 1

    return count_pair(ans)

sol = 0

# 모든 위치에 대해 폭탄을 터트려보고 최대값을 구한다.
for i in range(n):
    for j in range(n):
        sol = max(sol,best_boom(i,j,arr))

print(sol)