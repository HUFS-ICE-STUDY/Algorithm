s = input()
stack = []

for item in s:
    stack.append(item)
    if len(stack) >= 4:
        if stack[-4:] == ['P', 'P', 'A', 'P']:
            for _ in range(3):
                stack.pop()
if stack == ['P', 'P', 'A', 'P'] or stack == ['P']:
    print('PPAP')
else:
    print('NP')