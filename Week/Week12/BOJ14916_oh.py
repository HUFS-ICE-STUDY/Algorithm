n = int(input())

c5 = n // 5
c2 = 0

while(c5 >= 0):
    rest = n - 5 * c5

    if(rest % 2 == 0):
        c2 = rest // 2
        rest = 0
        break

    c5 -= 1

if(rest != 0):
    result = -1
else:
    result = c2 + c5

print(result)
