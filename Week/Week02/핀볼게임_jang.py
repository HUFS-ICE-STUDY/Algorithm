import sys
input = sys.stdin.readline

# 입력 받기
n = int(input())

arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

# 위아래 0, 아래위 1, 왼우 2, 우왼 3
dx = [1,-1,0,0]
dy = [0,0,1,-1]

dic1 = {0:3, 1:2, 2:1, 3:0} # / 를 만났을 때
dic2 = {0:2, 1:3, 2:0, 3:1} # \ 를 만났을 때

def pinball(x,y,state):
    count = 1
    while 0<=x<n and 0<=y<n:
        if arr[x][y] == 1:
            state = dic1[state]
        elif arr[x][y] == 2:
            state = dic2[state]

        x = x + dx[state]
        y = y + dy[state]
        count += 1
    return count

def pinball2(x,y,state):
    count = 1
    while True:
        if x<0 or y<0 or x>=n or y>=n:
            return count
        if arr[x][y] == 1:
            state = dic1[state]
        elif arr[x][y] == 2:
            state = dic2[state]
        x = x + dx[state]
        y = y + dy[state]
        count += 1

ans = 0
for i in range(n):
    # 위에서 아래
    ans = max(ans,pinball(0,i,0))
    # 왼쪽에서 오른쪽
    ans = max(ans,pinball(i,0,2))
    # 오른쪽에서 왼쪽
    ans = max(ans,pinball(i,n-1,3))
    # 아래에서 위로
    ans = max(ans,pinball(n-1,i,1))

print(ans)