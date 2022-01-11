import sys
import copy

input = sys.stdin.readline

n, k = map(int, input().split())

examples = [list(map(int, input().split())) for _ in range(n)]

dp = [0]*(k+1)
able_set = set()
able_set.add(0)

for w, v in examples:
    cur = set()
    temp = copy.deepcopy(dp)
    for i in able_set:
        if(i+w <= k):
            temp[i+w] = max(dp[i+w], dp[i]+v)
            cur.add(i+w)
    able_set = able_set.union(cur)
    dp = copy.deepcopy(temp)

print(max(dp))
