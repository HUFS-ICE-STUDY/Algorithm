import sys

input = sys.stdin.readline

s = input().rstrip()

stack = []
ppap = ['P', 'P', 'A', 'P']

for c in s:
    stack.append(c)

    if(stack[-4:] == ppap):
        for _ in range(4):
            stack.pop()
        stack.append('P')

if(stack == ppap or stack == ['P']):
    print('PPAP')
else:
    print('NP')
