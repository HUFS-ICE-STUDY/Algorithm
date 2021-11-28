def answer(s):   
    x,y = 499,499
    state = 0   # 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
    dic = { 0:(0,-1), 1:(1,0), 2:(0,1), 3:(-1,0) }
    l,r,u,d = 499,499,499,499
    for item in s:
        if item == 'F':
            tx,ty = dic[state]
            x += tx
            y += ty
        elif item == 'B':
            tx,ty = dic[state]
            x -= tx
            y -= ty
        elif item == 'L': 
            state = (state+4-1)%4
        elif item == 'R':
            state = (state+4+1)%4
        
        # 갱신
        if x>r: r = x
        if x<l: l = x
        if y>d: d = y
        if y<u: u = y

    return (r-l)*(d-u)

n = int(input())

for i in range(n):
    s = input()
    print(answer(s))