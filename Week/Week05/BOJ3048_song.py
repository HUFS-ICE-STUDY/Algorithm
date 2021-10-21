# 스왑 함수
def swap(a, b):
    temp = a
    a = b
    b = temp
    return a, b

n, m = map(int, input().split(" "))
a1 = list("".join(reversed(input())))
a2 = list(input())
ants = a1 + a2

dir = list()
for i in range(len(a1)):
    dir.append('R')
for i in range(len(a2)):
    dir.append('L')

t = int(input())
while t>0:
    # 파이썬은 for문에서 증가하는 index를 조절할 수 없으므로 while로 바꿔서 풀이
    i = 0
    while i<len(a1)+len(a2)-1:
        # i번째 개미의 방향이 오른쪽을 향하고 i+1번째 개미의 방향이 왼쪽을 향하는 경우 교환
        if(dir[i]=='R' and dir[i+1]=='L'):
            ants[i], ants[i+1] = swap(ants[i], ants[i+1])
            dir[i], dir[i+1] = swap(dir[i], dir[i+1])
            i += 1 # 이미 스왑한 문자를 다시 스왑하지 않기 위해서
        i += 1
    t -= 1
            
for i in ants:
    print(i, end="")