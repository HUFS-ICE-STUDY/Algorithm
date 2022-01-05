n, w, L = map(int, input().split())
trucks = list(map(int, input().split()))
 
bridge = [0] * w # 다리 길이만큼 배열 생성
time = 0
weight = 0

while bridge:
    weight -= bridge.pop(0)
    if trucks:
        if weight + trucks[0] <= L:
            temp = trucks.pop(0)
            bridge.append(temp)
            weight += temp
        else:
            bridge.append(0)
    time += 1

print(time)