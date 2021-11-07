import sys
input = sys.stdin.readline
arr = []
for i in range(int(input())):
    now = int(input())
    if now == 0:
        arr.pop()
    else:
        arr.append(now)
print(sum(arr))
