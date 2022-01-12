import sys
sys.setrecursionlimit(100000)

input = sys.stdin.readline

n,k = map(int,input().split())

W = []
V = []

for _ in range(n):
    w,v = map(int,input().split())
    W.append(w)
    V.append(v)

# def knapsack(n, capacity, size, value):
#     if capacity == 0 or n == 0:
#         return 0
#     if size[n - 1] > capacity:
#         return knapsack(n-1, capacity, size, value)
#     else:
#         return max(value[n - 1] + knapsack(n-1, capacity - size[n - 1], size, value),
#                    knapsack(n-1 , capacity, size, value))

def knapsack1(n, k):
    arr = [[0]*(k+1) for _ in range(n+1)]
    for i in range(1,n+1):
        for s in range(1,k+1):
            if W[i-1] > s:
                arr[i][s] = arr[i-1][s]
            else:
                arr[i][s] = max(V[i-1] + arr[i-1][s-W[i-1]], arr[i-1][s])
    return arr[n][k]    

print(knapsack1(n,k))