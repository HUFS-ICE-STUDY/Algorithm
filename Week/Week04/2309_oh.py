import sys

input = sys.stdin.readline

height = [int(input()) for _ in range(9)]

height.sort()

height_sum = sum(height)

for i in range(9):
    for j in range(i+1, 9):
        if(height_sum - height[i] - height[j] == 100):
            for idx in range(9):
                if(idx != i and idx != j):
                    print(height[idx])
            exit(0)
