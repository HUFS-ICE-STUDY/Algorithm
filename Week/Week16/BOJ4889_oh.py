import sys

input = sys.stdin.readline


def solution(s):
    stack = []
    open = 0
    result = 0

    for c in s:
        if(c == '{' or not stack):
            stack.append(c)
        else:
            if(stack[-1] == '{'):
                stack.pop()
            else:
                stack.append(c)

    for p in stack:
        if(p == '{'):
            open += 1
        else:
            if(open):
                open -= 1
            else:
                result += 1
                open += 1

    result += (open // 2)

    return result


num = 1

while(1):
    s = input().rstrip()

    if('-' in s):
        break

    print(f'{num}. {solution(s)}')
    num += 1
