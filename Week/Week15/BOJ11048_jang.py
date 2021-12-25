n,m = map(int,input().split())
arr = []
# 입력
for _ in range(n):
    arr.append(list(map(int,input().split())))

# 0열의 dp값 구하기
for i in range(1,n):
    arr[i][0] = arr[i][0] + arr[i-1][0]
# 0행의 dp값 구하기
for j in range(1,m):
    arr[0][j] = arr[0][j] + arr[0][j-1]

# dp 계산하기
for i in range(1,n):
    for j in range(1,m):
        arr[i][j] = arr[i][j] + max(arr[i][j-1], arr[i-1][j])

# 출력
print(arr[n-1][m-1])