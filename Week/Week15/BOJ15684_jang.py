import sys
input = sys.stdin.readline

n, m, h = map(int, input().split())
arr = [[0]*n for _ in range(h)]
ans = 4
for _ in range(m):
    # a선 점선 위치에 b~b+1 가로선
    a,b = map(int,input().split())
    arr[a-1][b-1] = 1

# 전부 사다리 타기
def check():
    # 0번 줄에서 n-1줄까지 체크한다
    for now in range(n):
        last = now
        for i in range(h):      # 가로줄 위치 개수만큼 반복
            if arr[i][last]:    # 가로줄이 오른쪽에 있으면 오른쪽으로 이동
                last += 1
            elif last > 0 and arr[i][last-1]:   # 가로줄이 왼쪽에 있으면 왼쪽 이동
                last -= 1
        if now != last: # 시작 숫자와 도착 숫자가 다른 경우 => 가로줄을 추가해야한다 False
            return False
    return True

def solution(cnt, x):
    global ans
    if ans <= cnt:  # ans를 최소값으로 갱신한 경우 cnt가 그 이상인 케이스를 계산할 필요가 없으니 스킵
        return      
    if check():     # 사다리가 잘 타지면 cnt로 갱신
        ans = cnt
        return
    if cnt == 3:    # 가로줄 4개 이상은 계산할 필요가 없으니 skip
        return
    for i in range(x, h):
        for j in range(n-1):
            if not arr[i][j]:
                arr[i][j] = 1
                solution(cnt+1, i) 
                arr[i][j] = 0

solution(0, 0)

print(ans if ans < 4 else -1)