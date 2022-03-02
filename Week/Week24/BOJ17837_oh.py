import sys

input = sys.stdin.readline

# 배열을 벗어나는지 판단


def pos(y, x):
    if(0 <= y < n and 0 <= x < n):
        return True
    return False


n, k = map(int, input().split())

# 체스판의 색을 입력받는 list
chess = [list(map(int, input().split())) for _ in range(n)]
# position[i] -> [y,x,d] -> i번째 말이 y행 x열 d방향을 보고 있음을 저장하는 list
position = []
# arr[y][x] -> y행 x열에 몇번 말들이 있는지 저장하는 list
arr = [[[] for _ in range(n)] for _ in range(n)]
# 움직이는 방향을 저장한 dictionary
move = {0: (0, 1), 1: (0, -1), 2: (-1, 0), 3: (1, 0)}
# 결과 값(턴)
turn = 0

for _ in range(k):
    y, x, d = map(int, input().split())

    position.append([y-1, x-1, d-1])

for p in enumerate(position):
    i = p[0]
    y, x, d = p[1]

    arr[y][x].append(i)

# 턴이 1000을 넘어가면 -1을 출력
while(turn <= 1000):
    turn += 1

    for i in range(k):
        # 움직이는 말을 저장해주는 list
        temp = []
        y, x, d = position[i]

        # stack 형식으로 i번 말이 나올 때까지 temp에 말들을 저장해준다.
        while(1):
            temp.append(arr[y][x].pop())
            if(temp[-1] == i):
                break

        # i번 말이 움직일 좌표 (ny,nx)
        ny, nx = y+move[d][0], x+move[d][1]
        # temp는 말들이 거꾸로 저장되어 있다.
        # 빨간색 칸일 경우에는 그대로 집어넣어도 되지만 아닌 경우는 편의를 위해서 reverse한 list도 만들어 준다.
        reverse_temp = list(reversed(temp))

        # 움직일 위치가 배열을 벗어나지 않고 파란칸이 아닌 경우
        if(pos(ny, nx) and chess[ny][nx] != 2):
            if(chess[ny][nx] == 0):
                arr[ny][nx] += reverse_temp
            else:
                arr[ny][nx] += temp
        else:
            # 벽에 막혀있거나 파란색 칸일 경우에 방향을 반대로 해준다.
            if(d == 0 or d == 2):
                d += 1
            else:
                d -= 1

            # 움직일 좌표
            ny, nx = y+move[d][0], x+move[d][1]
            # 방향을 바꿔준 것을 position에 최신화
            position[i][2] = d

            # 움직일 위치가 배열을 벗어나지 않고 파란칸이 아닌 경우
            if(pos(ny, nx) and chess[ny][nx] != 2):
                if(chess[ny][nx] == 0):
                    arr[ny][nx] += reverse_temp
                else:
                    arr[ny][nx] += temp
            else:
                # 양쪽 다 못가는 상황이면 다시 그 좌표에 넣어준뒤 다음 말을 이동한다.
                arr[y][x] += reverse_temp
                continue

        # 만약 이번 좌표에 말이 4개 이상 쌓일 경우 turn을 출력하고 종료
        if(len(arr[ny][nx]) >= 4):
            print(turn)
            exit(0)

        # 옮겨진 말들의 좌표를 최신화 해준다.
        for j in temp:
            position[j][0], position[j][1] = ny, nx

print(-1)
