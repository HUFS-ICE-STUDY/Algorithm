n = int(input())
request = list(map(int,input().split()))
total = int(input())

left,right = 0,max(request)
answer = 0
while (left <= right):
    mid = (left+right)//2
    score = 0
    for item in request:
        score += item if(mid>item) else mid
    if score > total:
        right = mid-1
    else:
        left = mid+1
        answer = mid

print(answer)