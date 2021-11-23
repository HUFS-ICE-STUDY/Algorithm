import sys

input = sys.stdin.readline

n, k = map(int, input().split())

arr = [int(input()) for _ in range(n)]

visit = [False]*n
cur = 0
cnt = 0

while(cur != k):
    if(visit[cur]):
        print(-1)
        exit(0)
    visit[cur] = True
    cur = arr[cur]
    cnt += 1

print(cnt)
