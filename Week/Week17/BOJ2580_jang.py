import sys
input = sys.stdin.readline

def check(x,y,num):
    for i in range(9):
        if arr[y][i] == num:
            return False
        if arr[i][x] == num:
            return False
    tx = (x//3)*3
    ty = (y//3)*3
    for a in range(3):
        for b in range(3):
            if arr[ty+a][tx+b] == num:
                return False
    return True

def solution(index):  
    if index == len(blank):
        for item in arr:
            print(*item)
        exit()

    for num in range(1,10):
        y,x = blank[index]
        if check(x,y,num):
            arr[y][x] = num
            solution(index+1)
            arr[y][x] = 0

arr = [[int(i) for i in input().split()] for _ in range(9)]
blank = [(i,j) for i in range(9) for j in range(9) if arr[i][j] == 0]

solution(0)