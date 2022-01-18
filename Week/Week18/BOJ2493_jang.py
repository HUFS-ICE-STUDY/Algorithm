n = int(input())
arr = list(map(int,input().split()))
answer = [0]*n
stack = []

# O(n)
for i in range(n):
    while stack:
        if stack[-1][1] > arr[i]:
            answer[i] = stack[-1][0] + 1
            break
        else:
            stack.pop()
    stack.append((i,arr[i]))

print(*answer)

# O(n^2)
# arr.reverse()
# for i in range(n-1):
#     for j in range(i+1,n):
#         if arr[j] > arr[i]:
#             answer[n-1-i] = n-j
#             break
# print(*answer)