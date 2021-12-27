import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

stack = [arr] + [[], []]
plate = n
cur = 0
cnt = 0
result = []

while(plate):
    if(not stack[cur]):
        cur = (cur+1) % 2
    else:
        if(stack[cur][-1] == plate):
            result.append([cur+1, 3])
            plate -= 1
        else:
            result.append([cur+1, (cur+1) % 2+1])
            stack[(cur+1) % 2].append(stack[cur][-1])
        stack[cur].pop()
        cnt += 1

print(cnt)
for i, j in result:
    print(i, j)
