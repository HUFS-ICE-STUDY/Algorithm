import sys

input = sys.stdin.readline

n = int(input())

num = list(map(int, input().split()))

num.sort()

result = 0

for i in range(n):
    temp = num[:i] + num[i+1:]
    left, right = 0, len(temp)-1

    while(left < right):
        t = temp[left] + temp[right]
        if(t == num[i]):
            result += 1
            break

        if(t < num[i]):
            left += 1
        else:
            right -= 1

print(result)
