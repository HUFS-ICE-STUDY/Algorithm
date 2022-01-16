import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline


def solution(a, b, c):
    if(visit[a][b][c]):
        return

    visit[a][b][c] = True

    if(a == 0):
        result.append(c)

    if(a != A):
        solution(a+min(A-a, b), b-min(A-a, b), c)
        solution(a+min(A-a, c), b, c-min(A-a, c))

    if(b != B):
        solution(a-min(B-b, a), b+min(B-b, a), c)
        solution(a, b+min(B-b, c), c-min(B-b, c))

    if(c != C):
        solution(a-min(C-c, a), b, c+min(C-c, a))
        solution(a, b-min(C-c, b), c+min(C-c, b))


A, B, C = map(int, input().split())

result = []
visit = [[[False for _ in range(C+1)] for _ in range(B+1)] for _ in range(A+1)]

solution(0, 0, C)

result.sort()

print(*result)
