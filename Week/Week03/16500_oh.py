import sys

sys.setrecursionlimit(100000000)


def solution(start):
    if(start == len(s)):
        print(1)
        exit()

    for i in temp[start]:
        if(not visit[i]):
            visit[i] = True
            solution(i)


input = sys.stdin.readline

s = input().rstrip()
n = int(input())
words = {input().rstrip() for _ in range(n)}
visit = [False]*(len(s)+1)
temp = dict()

for i in range(len(s)):
    temp[i] = []

for i in range(len(s)):
    for j in range(i, len(s)):
        if(s[i:j+1] in words):
            temp[i].append(j+1)

for i in temp[0]:
    if(not visit[i]):
        visit[i] = True
        solution(i)

print(0)
