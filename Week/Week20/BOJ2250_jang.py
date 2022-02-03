# 전위 순회
def pre(node,depth):
    global index
    if graph[node][0] != -1:
        pre(graph[node][0], depth + 1)
    
    # 해당 깊이에 노드의 인덱스를 저장
    resgraph[depth].append(index)
    index+=1
    if graph[node][1]!=-1:
        pre(graph[node][1],depth+1)

#기본 입력
n = int(input())
graph = [[] for i in range(n+1)]
check = []
for _ in range(n):
    a,b,c = map(int,input().split())
    graph[a].append(b)
    graph[a].append(c)
    check.append(b)
    check.append(c)

check = set(check)
    
# 리스트의 index는 트리의 depth(세로)이며 index 변수에는 원소의 위치(가로)를 저장
resgraph=[[] for _ in range(n+1)]
node = 0
for i in range(n+1):
    if graph[i]:
        if i not in check:
            node = i
index = 1

pre(node,index)

#인덱스 차 가장 큰 값 선별
maxlength=0
resdepth=0
for i in range(1,n+1):
    if resgraph[i]:
        last = resgraph[i][-1]
        first = resgraph[i][0]
        if last-first + 1 > maxlength:
            maxlength = last - first + 1
            resdepth = i
    else:
        break
print(resdepth, maxlength)

# 참고 코드 - 백준 dlehrud451님 코드
# https://www.acmicpc.net/board/view/81840