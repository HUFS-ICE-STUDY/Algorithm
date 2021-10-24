import sys

input = sys.stdin.readline

n1, n2 = map(int, input().split())

a1 = input().rstrip()
a2 = input().rstrip()
t = int(input())

cur = list(a1[::-1] + a2)

for _ in range(t):
    idx = 0

    while(idx < n1+n2-1):
        if(cur[idx] in a1):
            if(cur[idx+1] in a1):
                idx += 1
            else:
                cur[idx], cur[idx+1] = cur[idx+1], cur[idx]
                idx += 2
        else:
            idx += 1

print(''.join(cur))
