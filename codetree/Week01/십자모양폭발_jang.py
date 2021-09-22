# 변수 선언 및 입력:
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

x,y = map(int,(input().split()))
x,y = x-1,y-1

# 배열 범위 확인
def in_range(x,y):
    if(0<=x<n and 0<=y<n): return True
    return False

count = arr[x][y]

# 폭탄 범위 만큼 0으로 만든다
for i in range(count):
    if(in_range(x-i, y)):
        arr[x-i][y] = 0
    if(in_range(x+i, y)):
        arr[x+i][y] = 0
    if(in_range(x, y-i)):
        arr[x][y-i] = 0
    if(in_range(x, y+i)):
        arr[x][y+i] = 0

ans = [[0]*n for _ in range(n)]

# 폭탄을 터지고 중력이 작용
for i in range(n):
    temp = n-1
    for j in range(n):
        if arr[n-1-j][i]:
            ans[temp][i] = arr[n-1-j][i]
            temp -= 1

# 출력
for i in range(n):
    print(*ans[i])