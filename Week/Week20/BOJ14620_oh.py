import sys
from itertools import combinations

input = sys.stdin.readline

n = int(input())

flower = [list(map(int, input().split())) for _ in range(n)]

# 상하좌우
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]
# 씨앗을 심을 수 있는 위치를 저장하는 배열
arr = [(y, x) for y in range(1, n-1) for x in range(1, n-1)]
# 결과값
result = sys.maxsize

# arr에서 3개를 고르는 모든 경우
loc = list(combinations(arr, 3))

for i in loc:
    # 꽃이 핀 지역
    temp = []
    # i에 있는 3개의 지점에 씨앗을 심었을 때, 3개 다 꽃이 피는 경우
    able = True
    # i에 씨앗을 심을 때 드는 비용
    cost = 0
    for y, x in i:
        if((y, x) in temp):
            able = False
            break
        cost += flower[y][x]
        temp.append((y, x))
        for j in range(4):
            ny = y + dy[j]
            nx = x + dx[j]

            if((ny, nx) in temp):
                able = False
                break

            temp.append((ny, nx))
            cost += flower[ny][nx]

    if(able):
        result = min(result, cost)

print(result)
