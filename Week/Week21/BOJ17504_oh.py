import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

up, down = 1, arr[-1]

arr = list(reversed(arr))

for i in arr[1:]:
    up += (down*i)
    up, down = down, up

print(down-up, down)
