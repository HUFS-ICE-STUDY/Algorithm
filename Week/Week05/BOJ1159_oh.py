import sys

input = sys.stdin.readline

n = int(input())

players = [input().rstrip() for _ in range(n)]
result = ''
temp = ''
cnt = 0

players.sort()

for player in players:
    if(temp == player[0]):
        cnt += 1
    else:
        if(cnt >= 5):
            result += temp

        temp = player[0]
        cnt = 1

if(cnt >= 5):
    result += temp

if(result):
    print(result)
else:
    print('PREDAJA')
