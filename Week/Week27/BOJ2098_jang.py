n = int(input())
graph = [list(map(int,input().split())) for _ in range(n)]
INF = int(1e9)
dp = [[INF]*(1<<n) for _ in range(n)]

def tsp(x,visited):
    if visited == (1<<n)-1:     # 모든 도시를 방문 했다먼?
        if graph[x][0]: # 출발점으로 가는 경로가 있다면 0 가는 비용 return
            return graph[x][0]
        else:           # 출발점으로 가는 경로가 없다면 INF return
            return INF  
    
    if dp[x][visited] != INF:   # 이미 최소 비용이 계산된 경우
        return dp[x][visited]
    
    for i in range(1,n):        # 모든 도시를 탐방
        if not graph[x][i]:     # 가는 경로가 없는 경우 스킵
            continue
        if visited & (1 << i):  # 이미 방문한 도시 스킵
            continue
        # dp : 현재 도시에서 남은 도시들을 거쳐 다시 출발점으로 돌아오는 비용을 저장
        # dp[x][visited] : 현제 x 도시에 있으며, 방문 현황은 visited.
        # 아직 방문하지 않은 도시들을 모두 거쳐 다시 시작점으로 가는데 드는 최소비용
        # dp[1][0011] : 현재 1번 도시, 0,1번 도시 방문, 2,3을 방문하고 시작점으로 돌아가는데 드는 최소비용
        # dp[2][0111] : 현재 2번 도시, 0,1,2번 도시 방문, 3을 방문하고 시작점으로 돌아가는데 드는 비용
        # 따라서 dp[1][0011] = dp[2][0111] + graph[1][2]

        dp[x][visited] = min(dp[x][visited], tsp(i, visited | (1 << i)) + graph[x][i])
    return dp[x][visited]

print(tsp(0,1))