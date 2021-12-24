import sys
input = sys.stdin.readline  # 넣어주지 않으면 시간초과 발생

n,p = map(int,input().split())

lines = [[] for _ in range(6)]
result = 0

for i in range(n):
    # 연주할 멜로디를 입력 받는다.
    # l : 줄의 번호, p : 프렛의 번호
    l,p = map(int,input().split())

    # 눌러야 하는 음이 손을 떼야만 하는 경우
    while(lines[l-1] and lines[l-1][-1] > p):
        # 손을 떼고 손가락 움직임을 증가시킨다.
        lines[l-1].pop()
        result += 1

    # 현을 눌러야 음을 연주할 수 있는 경우
    if(not lines[l-1] or lines[l-1][-1] < p):
        lines[l-1].append(p)
        result += 1

# 멜로디를 연주하는데 필요한 최소 손가락 움직임을 출력
print(result)