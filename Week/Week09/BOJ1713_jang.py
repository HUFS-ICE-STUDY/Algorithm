from collections import defaultdict

dict = defaultdict(lambda: 0) # 딕셔너리에 키값을 넣을때 값을 0으로 초기화
n = int(input())
k = int(input())
arr = list(map(int,input().split()))

for item in arr:
    if len(dict) == n:
        if item not in dict.keys():
            key = list(dict.keys())
            val = list(dict.values())
            min_idx = val.index(min(val))
            del(dict[key[min_idx]])
    dict[item] += 1

print(*sorted(list(dict.keys())))