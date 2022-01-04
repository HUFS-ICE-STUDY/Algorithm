case = []
while True:
    t = input()
    if t[0] == '-':
        break
    else:
        case.append(t)
num = 1
for i in range(len(case)):
    s1 = []
    count = 0
    s = case[i]
    s1.append('{')
    if s[0] == '}':
        count += 1
    for j in range(1,len(s)):
        if s[j] == '{':
            s1.append('{')
        elif s[j] == '}':
            if len(s1) == 0:
                s1.append('{')
                count += 1
            else:
                s1.pop()
    print(f'{num}. {count+len(s1)//2}')
    num += 1