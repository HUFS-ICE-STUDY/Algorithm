n = int(input())

arr = [3, 7]

for _ in range(n-2):
    idx = len(arr)-1
    k = (arr[idx]*2 + arr[idx-1]) % 9901
    arr.append(k)

print(arr[n-1])
