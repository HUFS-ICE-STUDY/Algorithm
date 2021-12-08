n,m = map(int,input().split())
arr = list(map(int,input().split()))
this_month = []

for item in arr:
    this_month.append(abs(item))

month = set(this_month)

for _ in range(m-1):
    month = set(i^j for i in this_month for j in month)

print(max(month))



"""
n,m = map(int,input().split())
arr = list(map(int,input().split()))
this_month = []

for item in arr:
    this_month.append(abs(item))

month = set(this_month)

for _ in range(m-1):
    temp = set([])
    for i in this_month:
        for j in month:
            temp.add(i^j)
    month = temp

print(max(month))

"""