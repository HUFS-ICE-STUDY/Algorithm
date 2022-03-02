import sys

input = sys.stdin.readline

n, m = map(int, input().split())

paper = [list(input().rstrip()) for _ in range(n)]
result = 0

# 비트마스킹을 이용해 2**(n*m)-1 가지의 수를 모두 해본 뒤 최대 값을 찾아냄.
# 0인 경우는 가로로 길게 된 종이, 1인 경우는 세로로 길게 된 종이
# 연속으로 0이 있거나 1이 있으면 연속되는 종이가 무조건 더 큰 수가 되기 때문에
# 0이 가로로 있으면 하나의 종이로 판단하고, 1이 세로로 있으면 하나의 종이로 판단해 최대 값을 구한다
for num in range(2**(n*m)):
    k = 0

    for y in range(n):
        temp = 0
        for x in range(m):
            if(num & (1 << (y*m + x))):
                k += temp
                temp = 0
            else:
                temp *= 10
                temp += int(paper[y][x])
        k += temp

    for x in range(m):
        temp = 0
        for y in range(n):
            if(num & (1 << (y*m + x))):
                temp *= 10
                temp += int(paper[y][x])
            else:
                k += temp
                temp = 0
        k += temp

    result = max(result, k)

print(result)
