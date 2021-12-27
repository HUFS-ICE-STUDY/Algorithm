import sys
import copy
sys.setrecursionlimit(10*6)

input = sys.stdin.readline


def solution(game, cnt):
    global result

    result = max(result, max(map(max, game)))

    if(cnt == 5):
        return

    solution(move(game, 0), cnt+1)
    solution(move(game, 1), cnt+1)
    solution(move(game, 2), cnt+1)
    solution(move(game, 3), cnt+1)


def move(game, d):
    temp = [[0]*n for _ in range(n)]

    if(d == 0):
        for i in range(n):
            temp_arr = []
            temp_result = [0]*n
            idx = 0

            for j in range(n):
                if(game[i][j]):
                    temp_arr.append(game[i][j])

            if(temp_arr):
                before = -1
                for k in temp_arr:
                    if(before == -1):
                        before = k
                    elif(k == before):
                        temp_result[idx] = k*2
                        before = -1
                        idx += 1
                    else:
                        temp_result[idx] = before
                        before = k
                        idx += 1

                if(before != -1):
                    temp_result[idx] = before

            for k in range(n):
                temp[i][k] = temp_result[k]

    elif(d == 1):
        for i in range(n):
            temp_arr = []
            temp_result = [0]*n
            idx = 0

            for j in range(n):
                if(game[j][i]):
                    temp_arr.append(game[j][i])

            if(temp_arr):
                before = -1
                for k in temp_arr:
                    if(before == -1):
                        before = k
                    elif(k == before):
                        temp_result[idx] = k*2
                        before = -1
                        idx += 1
                    else:
                        temp_result[idx] = before
                        before = k
                        idx += 1

                if(before != -1):
                    temp_result[idx] = before

            for k in range(n):
                temp[k][i] = temp_result[k]
    elif(d == 2):
        for i in range(n):
            temp_arr = []
            temp_result = [0]*n
            idx = n-1

            for j in range(n-1, -1, -1):
                if(game[i][j]):
                    temp_arr.append(game[i][j])

            if(temp_arr):
                before = -1
                for k in temp_arr:
                    if(before == -1):
                        before = k
                    elif(k == before):
                        temp_result[idx] = k*2
                        before = -1
                        idx -= 1
                    else:
                        temp_result[idx] = before
                        before = k
                        idx -= 1

                if(before != -1):
                    temp_result[idx] = before

            temp_result.reverse()

            for k in range(n):
                temp[i][k] = temp_result[k]
    else:
        for i in range(n):
            temp_arr = []
            temp_result = [0]*n
            idx = n-1

            for j in range(n-1, -1, -1):
                if(game[j][i]):
                    temp_arr.append(game[j][i])

            if(temp_arr):
                before = -1
                for k in temp_arr:
                    if(before == -1):
                        before = k
                    elif(k == before):
                        temp_result[idx] = k*2
                        before = -1
                        idx -= 1
                    else:
                        temp_result[idx] = before
                        before = k
                        idx -= 1

                if(before != -1):
                    temp_result[idx] = before

            temp_result.reverse()

            for k in range(n):
                temp[k][i] = temp_result[k]

    return temp


n = int(input())

game = [list(map(int, input().split())) for _ in range(n)]
result = 0

if(n == 1):
    result = game[0][0]
else:
    solution(game, 0)

print(result)
