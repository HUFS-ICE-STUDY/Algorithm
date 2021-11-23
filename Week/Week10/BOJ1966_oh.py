def importance(arr, m):
    result = 0

    while(True):
        queue = []

        for idx in range(len(arr)):
            if(arr[idx] != max(arr)):
                queue.append(arr[idx])
            else:
                if(idx == m):
                    return result + 1
                else:
                    arr[idx] = -1
                    queue.append(arr[idx])
                    result += 1

        arr = queue.copy()


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    result = 0

    print(importance(arr, m))
