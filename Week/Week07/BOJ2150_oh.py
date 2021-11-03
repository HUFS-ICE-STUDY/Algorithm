import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

V, E = map(int, input().split())
visited = [0] * (V+1)
graph = [[] for i in range(V + 1)]

for _ in range(E):
    a, b = map(int, input().split())
    graph[a].append(b)


def dfs(v, visited, stack):
    visited[v] = 1

    for w in graph[v]:
        if visited[w] == 0:
            stack.append(w)
            dfs(w, visited, stack)
    stack.append(v)


def reverseGraph():
    reverse_graph = [[] for i in range(V+1)]
    for i in range(1, V+1):
        for j in graph[i]:
            reverse_graph[j].append(i)
    return reverse_graph


def reverseDfs(v, visited, stack):
    visited[v] = 1
    stack.append(v)
    for w in reverse_graph[v]:
        if visited[w] == 0:
            reverseDfs(w, visited, stack)


stack = []
for i in range(1, V+1):
    if visited[i] == 0:
        dfs(i, visited, stack)

reverse_graph = reverseGraph()

visited = [0] * (V+1)
results = []

while stack:
    ssc = []
    node = stack.pop()
    if visited[node] == 0:
        reverseDfs(node, visited, ssc)
        results.append(sorted(ssc))

print(len(results))
results = sorted(results)

for i in results:
    for j in i:
        print(j, end=' ')
    print('-1')
