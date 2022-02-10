from collections import deque
n,l,r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
day = 0
graph = dict()  # key: 해당 좌표의 국가, value: 연결된 국가

# 국경 그리기
def border(i, j):
    value = []
    if (i-1) >= 0:
        temp = abs(arr[i-1][j] - arr[i][j])
        if temp >= l and temp <= r:
            value.append((i-1,j))
    if (i+1) < n:
        temp = abs(arr[i+1][j] - arr[i][j])
        if temp >= l and temp <= r:
            value.append((i+1,j))
    if (j-1) >= 0:
        temp = abs(arr[i][j-1] - arr[i][j])
        if temp >= l and temp <= r:
            value.append((i,j-1))
    if (j+1) < n:
        temp = abs(arr[i][j+1] - arr[i][j])
        if temp >= l and temp <= r:
            value.append((i,j+1))
    if value:
        graph[(i,j)] = value

def bfs(start):
    visit = []
    queue = deque()
    queue.append(start)
    while queue:
        position = queue.popleft()
        if position not in visit:
            visit.append(position)
            queue.extend(graph[position])
    return visit

while True:
    # 매일마다 인접 리스트 그리기
    for i in range(n):
        for j in range(n):
            border(i,j)

    # 연합이 아무도 없는 경우
    if not graph:
        break

    # 인구 이동
    while graph:
        # 방문 위치와 연결된 연합을 방문시킨다 
        visited = bfs(list(graph.keys())[0])
        sum = 0
        # 인구수 조정
        for item in visited:
            sum += arr[item[0]][item[1]]
        result = int(sum/len(visited))
        for item in visited:
            arr[item[0]][item[1]] = result
            del(graph[item])    # 연합 해제
    day += 1

print(day)