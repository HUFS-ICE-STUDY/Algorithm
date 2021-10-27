# 1) 방문여부 검사 
# 2) 이전위치에서 이동 가능한지 검사 
# 3) 마지막 위치
arr = [input() for _ in range(36)]
move = [[-2, -1], [-2, 1], [-1, -2], [1, -2], [2, -1], [2, 1], [1, 2], [-1, 2]]

if len(set(arr)) == 36:
    for i in range(35):
        if abs((ord(arr[i][0])-ord(arr[i+1][0]))) + abs((int(arr[i][1])-int(arr[i+1][1]))) != 3:
            print('Invalid')
            break
    else:
        x = ord(arr[0][0]) - ord('A')
        y = int(arr[0][1]) - 1

        for i in range(1,36):
            nx = ord(arr[i][0]) - ord('A')
            ny = int(arr[i][1]) - 1
            if abs(nx-x)>2 or abs(ny-y)>2:
                print('Invalid')
                break
            if nx>5 or ny>5:
                print('Invalid')
                break
            if [nx-x,ny-y] in move:
                x = nx
                y = ny
            else:
                print('Invalid')
                break
        else:
            if abs(ord(arr[0][0]) - ord('A') - x) > 2 or abs(int(arr[0][1])-1 - y)>2:
                print("Invalid")
            else:
                print('Valid')
else:
    print('Invalid')