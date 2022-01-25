import sys
import heapq

input = sys.stdin.readline


n = int(input())
m = int(input())
# 비용을 저장하는 딕셔너리
cost = dict()
# 해당 노드를 방문했는지 판단해주는 리스트
visit = [False]*(n+1)
# 간선의 수 -> 간선의 수가 n-1개가 최대가 되도록 한다
cnt = 0
# 최소 비용
result = 0

for i in range(1, n+1):
    cost[i] = dict()

for _ in range(m):
    f, t, c = map(int, input().split())

    cost[f][t] = c
    cost[t][f] = c

# 최소 스패닝 트리(MST) Prim 알고리즘 사용 -> heapq(우선순위 큐) 이용
queue = [(0, 1)]

while(cnt < n):
    c, node = heapq.heappop(queue)
    # 이미 방문한 노드인 경우
    if(visit[node]):
        continue
    # 노드를 방문했다고 해준 뒤, 결과값에 비용을 더해주고 간선이 하나 추가되었다고 해준다.
    visit[node] = True
    result += c
    cnt += 1

    for next_node, next_cost in cost[node].items():
        if(not visit[next_node]):
            heapq.heappush(queue, (next_cost, next_node))

print(result)
