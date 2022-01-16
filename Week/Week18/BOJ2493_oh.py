import sys

input = sys.stdin.readline

n = int(input())

h = list(map(int, input().split()))

stack = []
result = []

for i in range(n):
    while(1):
        if(not stack):
            result.append(0)
            stack.append((h[i], i+1))
            break

        if(stack[-1][0] < h[i]):
            stack.pop()
        else:
            result.append(stack[-1][1])
            stack.append((h[i], i+1))
            break

print(*result)