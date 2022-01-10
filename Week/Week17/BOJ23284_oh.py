import sys
import copy

input = sys.stdin.readline


def solution(i, stack, cur):
    if(i > n):
        stack.reverse()
        result.append(cur + stack)
        return

    solution(i+1, stack+[i], cur)
    if(stack):
        temp = copy.deepcopy(stack[:-1])
        solution(i, temp, cur+[stack[-1]])


n = int(input())

result = []

solution(1, [], [])

result.sort()

for i in result:
    print(*i)
