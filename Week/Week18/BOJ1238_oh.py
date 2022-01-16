import sys
import heapq

input = sys.stdin.readline

n, m, x = map(int, input().split())

roads = [list(map(int, input().split())) for _ in range(m)]

start_path = dict()
end_path = dict()

for i in range(1, n+1):
    start_path[i] = dict()
    end_path[i] = dict()

for s, e, t in roads:
    start_path[e][s] = t
    end_path[s][e] = t

start_result = [sys.maxsize]*(n+1)
start_result[x] = 0
queue = []

heapq.heappush(queue, [start_result[x], x])

while(queue):
    cur_cost, cur_node = heapq.heappop(queue)

    if(cur_cost > start_result[cur_node]):
        continue

    for adj, c in start_path[cur_node].items():
        c += cur_cost

        if(c < start_result[adj]):
            start_result[adj] = c
            heapq.heappush(queue, [c, adj])

end_result = [sys.maxsize]*(n+1)
end_result[x] = 0
queue = []

heapq.heappush(queue, [end_result[x], x])

while(queue):
    cur_cost, cur_node = heapq.heappop(queue)

    if(cur_cost > end_result[cur_node]):
        continue

    for adj, c in end_path[cur_node].items():
        c += cur_cost

        if(c < end_result[adj]):
            end_result[adj] = c
            heapq.heappush(queue, [c, adj])

temp = 0

for i in range(1, n+1):
    temp = max(temp, start_result[i]+end_result[i])

print(temp)
