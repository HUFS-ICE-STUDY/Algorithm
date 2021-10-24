n = int(input())
arr = []
for i in range(n):
    arr.append(input()[0])

count={}
for i in arr:
    try: count[i] += 1
    except: count[i]=1

ans = []
for key,val in count.items():
    if val>=5: 
        ans.append(key)
ans.sort()
if ans: 
    for item in ans:
        print(item, end='')
else: 
    print('PREDAJA')