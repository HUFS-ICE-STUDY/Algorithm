n,m = map(int,input().split())
arr = [[0]*m for _ in range(n)]
result = 0
visited = [[False]*m for _ in range(n)]

for i in range(n):
    s = input()
    for j in range(m):
        arr[i][j] = int(s[j])

# 브루드포스(0~m*n-1를 돌면서 모든 경우의 수를 확인)
def max_sum(num, sum):
    global result
    x = num // m
    y = num % m

    if num >= n*m:
        result = max(result, sum)
        return

    if visited[x][y]:
        max_sum(num+1, sum)
    else:
        # (x,y)의 원소만으로 이루어진 종이조각 계산
        value = arr[x][y]
        visited[x][y] = True
        max_sum(num+1, value+sum)
        visited[x][y] = False

        # (x,y)의 원소와 그 아래에 있는 원소들로 이루어진 종이 조각 계산
        for i in range(1,n-x):
            nx = x + i
            ny = y
            value *= 10
            value += arr[nx][ny]

            if visited[nx][ny]:
                return

            for j in range(1,i+1):
                visited[x+j][ny] = True
            max_sum(num+1, value+sum)
            for j in range(1,i+1):
                visited[x+j][ny] = False
        
        value = arr[x][y]
        # (x,y)의 원소와 그 오른쪽에 있는 원소들로 이루어진 종이 조각 계산
        for i in range(1,m-y):
            nx = x
            ny = y + i
            value *= 10
            value += arr[nx][ny]

            if visited[nx][ny]:
                return

            for j in range(1,i+1):
                visited[nx][y+j] = True
            max_sum(num+1, value+sum)
            for j in range(1,i+1):
                visited[nx][y+j] = False

max_sum(0,0)

print(result)