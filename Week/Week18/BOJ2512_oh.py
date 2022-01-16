import sys

n = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())

left = 0
right = max(arr)
result = 0

while(left <= right):
    mid = (left + right) // 2
    cnt = 0

    for money in arr:
        if(money >= mid):
            cnt += mid
        else:
            cnt += money

    if(cnt > m):
        right = mid - 1
    else:
        result = max(result, mid)
        left = mid + 1

print(result)
