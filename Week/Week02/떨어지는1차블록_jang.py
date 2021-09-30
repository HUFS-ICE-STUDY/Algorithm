# 입력 받기
# n : 격자판크기 m : 1*m 블록 k : 블록 시작 열()
n,m,k = map(int,input().split())
k -= 1

arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

# 1개 짜리 블록일 경우: 무조건 1 한칸짜리 배열이 된다.
if n == 1:
    print(1)
    exit()

# 블록이 막힐경우 막힌 것 이전 열의 블록 길이만큼 1을 채워주고 함수종료
def drop_block():
    for i in range(1,n):
        for j in range(k,k+m):
            if arr[i][j] != 0:
                for j in range(k,k+m):
                    arr[i-1][j] = 1
                return
drop_block()

# 출력
for i in range(n):
    print(*arr[i])