import sys
r = sys.stdin.readline


def DFS(idx):
    if(idx == len(zeros)):
        for i in range(9):
            for j in range(9):
                print(puzzle[i][j], end=' ')
            print()
        sys.exit(0)
    else:
        for num in range(1, 10):
            x = zeros[idx][1]
            y = zeros[idx][0]

            if(possible(y, x, num)):
                puzzle[y][x] = num
                DFS(idx+1)
                puzzle[y][x] = 0


def possible(y, x, num):
    sq_x = x // 3 * 3
    sq_y = y // 3 * 3

    for idx in range(9):
        if(puzzle[idx][x] == num):
            return False

    for i in range(3):
        for j in range(3):
            if(num == puzzle[sq_y + i][sq_x + j]):
                return False

    if(num in puzzle[y]):
        return False

    return True


puzzle = [list(map(int, r().split())) for _ in range(9)]
zeros = [(i, j) for i in range(9) for j in range(9) if puzzle[i][j] == 0]

DFS(0)
