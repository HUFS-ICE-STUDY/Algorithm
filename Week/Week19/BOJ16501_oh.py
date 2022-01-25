import sys

input = sys.stdin.readline

scores = list(map(int, input().split()))
visit = [False]*8
temp = sys.maxsize

for a in range(8):
    visit[a] = True
    for b in range(8):
        if(visit[b]):
            continue
        visit[b] = True
        for c in range(8):
            if(visit[c]):
                continue
            visit[c] = True
            for d in range(8):
                if(visit[d]):
                    continue
                visit[d] = True
                for e in range(8):
                    if(visit[e]):
                        continue
                    visit[e] = True
                    for f in range(8):
                        if(visit[f]):
                            continue
                        visit[f] = True
                        for g in range(8):
                            if(visit[g]):
                                continue
                            visit[g] = True
                            for h in range(8):
                                if(visit[h]):
                                    continue
                                visit[h] = True
                                temp = min(temp, max((abs((scores[a]+scores[b]) - (scores[c]+scores[d])) / 2, abs((
                                    scores[e]+scores[f]) - (scores[g]+scores[h])) / 2)))
                                visit[h] = False
                            visit[g] = False
                        visit[f] = False
                    visit[e] = False
                visit[d] = False
            visit[c] = False
        visit[b] = False
    visit[a] = False

result = 1 - temp / 10

print(result)
