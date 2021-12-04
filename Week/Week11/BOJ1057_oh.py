import sys

ipnut = sys.stdin.readline

n, k, l = map(int, input().split())

k -= 1
l -= 1
cnt = 0

while(k != l):
    k //= 2
    l //= 2
    cnt += 1

print(cnt)
