import sys

input = sys.stdin.readline

arr = list(map(int, input().split()))
result = [1, 1, 2, 2, 2, 8]

for i in range(len(arr)):
    print(result[i]-arr[i], end=' ')
