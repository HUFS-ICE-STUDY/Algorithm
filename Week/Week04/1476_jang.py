e,s,m = map(int,input().split())

a1,a2,a3 = 0,0,0
count = 0
while True:
    if a1 == e and a2 == s and a3 == m:
        break

    a1 += 1
    a2 += 1
    a3 += 1
    count += 1

    if a1 == 16: a1 = 1
    if a2 == 29: a2 = 1
    if a3 == 20: a3 = 1
print(count)