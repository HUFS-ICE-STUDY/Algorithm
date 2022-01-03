import sys

input = sys.stdin.readline

n, w, l = map(int, input().split())

trucks = list(map(int, input().split()))

bridge = [0]*w
result = 0
idx = 0

while(idx < len(trucks)):
    bridge = [0] + bridge[:-1]

    weight = sum(bridge)

    if(weight + trucks[idx] <= l):
        bridge[0] = trucks[idx]
        idx += 1

    result += 1

print(result + w)
