import heapq
import collections
import sys

input = sys.stdin.readline

n, m = map(int,input().split()) # 노드 수, 간선 수
graph = collections.defaultdict(list) # 빈 그래프 생성
# defaultdict : key값이 없을 경우 
# 미리 지정해 놓은 초기(default)값을 반환하는 dictionary

visited = [0] * (n+1) # 노드의 방문 정보 초기화

# 무방향 그래프 생성
for i in range(m): # 간선 정보 입력 받기
    u, v, weight = map(int,input().split())
    graph[u].append([weight, u, v])
    graph[v].append([weight, v, u])

# 방문한 노드인지 확인을 하고 우선순위 큐에 삽입을 합니다.
def prim(graph,start_node):
    visited[start_node] = 1 # 첫 방문을 갱신
    candidate = graph[start_node] # 인접한 간선을 추출
    heapq.heapify(candidate)    # 우선순위 큐 생성
    mst = [] # 최소 신장 트리 생성
    total_weight = 0 # 전체 가중치

    while candidate:
        weight,u,v = heapq.heappop(candidate) # 가중치가 가장 적은 간선을 추출한다.
        if visited[v] == 0: # 방문하지 않았다면
            visited[v] = 1  # 방문처리
            mst.append((u,v))       # mst에 간선 삽입
            total_weight += weight  # 전체 가중치를 갱신

            for edge in graph[v]:   # 다음 인접 간선 탐색
                if visited[edge[2]] == 0:   # 방문한 노드가 아니라면(순환 방지 목적)
                    heapq.heappush(candidate,edge) # heapq에 edge를 삽입
    
    return total_weight,mst

total_weight,mst = prim(graph,1)
# print(mst)  # 최소 신장 트리를 출력한다.
print(total_weight) # 전체 가중치를 출력한다.

# 참고자료
# https://deep-learning-study.tistory.com/595