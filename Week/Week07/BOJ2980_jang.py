N,L = map(int,input().split())
arr = []
time = 0
now_d = 0
for i in range(N):
    d,r,g = map(int,input().split())
    time += (d-now_d)
    now_d += (d-now_d)
    if time%(r+g) >= r:
        continue
    else:
       time += (r-time%(r+g))
time += (L-d)
print(time)