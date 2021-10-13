import sys

input = sys.stdin.readline

n, m = map(int, input().split())

balls = [i for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())

    balls[a], balls[b] = balls[b], balls[a]

for ball in balls[1:]:
    print(ball, end=' ')
