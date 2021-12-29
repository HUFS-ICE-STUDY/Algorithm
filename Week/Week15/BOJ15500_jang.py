import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
check = sorted(arr)

s1 = arr[:]
s2 = []

ans = []

while check:
    plate = check.pop()
    if plate in s1:
        while s1:
            temp = s1.pop()
            if temp == plate:
                ans.append((1,3))
                break
            else:
                s2.append(temp)
                ans.append((1,2))
    elif plate in s2:
        while s2:
            temp = s2.pop()
            if temp == plate:
                ans.append((2,3))
                break
            else:
                s1.append(temp)
                ans.append((2,1))
print(len(ans))
for i,j in ans:
    print(i,j)