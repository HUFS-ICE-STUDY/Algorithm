import sys
input = sys.stdin.readline
R, C = map(int,input().split())

map = []
for i in range(R):
    map.append(list(input()))

arr = [[0]*(C+2) for _ in range(R+2)]

for i in range(1,R+1):
    for j in range(1,C+1):
        if map[i-1][j-1] == 'X':
            arr[i][j] = 1

for i in range(1,R+1):
    for j in range(1,C+1):
        count = 0
        if arr[i][j] == 1:
            if arr[i-1][j] == 0:    # 상
                count += 1
            if arr[i+1][j] == 0:    # 하
                count += 1
            if arr[i][j-1] == 0:    # 좌
                count += 1
            if arr[i][j+1] == 0:    # 우
                count += 1
            if count >= 3:
                arr[i][j] = 2

left, right, up, down = C+2,0,R+2,0
# 최대의 right, up, 최소의 left, down을 구한다
for i in range(R+2):
    for j in range(C+2):
        if arr[i][j] == 1:
            if left > j:
                left = j
            if right < j:
                right = j
            if up > i:
                up = i
            if down < i:
                down = i

for i in range(up,down+1): 
    for j in range(left,right+1):
        if arr[i][j] == 1:
            print('X', end='')
        else:
            print('.', end='')
    print()

"""
['.', '.', '.', '.', '.', '.', '.', '.', '.', '.']
['.', '.', 'X', 'X', 'X', '.', 'X', 'X', 'X', '.']
['X', 'X', 'X', '.', '.', '.', '.', '.', '.', '.']

[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0]
[0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 1, 1, 2, 0, 2, 1, 2, 0, 0]
[0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

2 8 2 3

.XX...X
XX.....

"""














# import sys
# input = sys.stdin.readline
# R, C = map(int,input().split())
# map = []
# answer = []
# map.append(['.']*(C+2))
# for i in range(R):
#     temp = list(input().rstrip())
#     map.append(['.']+temp+['.'])
# map.append(['.']*(C+2))

# for i in range(1,R+1):
#     if map[i].count('X'):
#         ans_str = []
#         for j in range(1,C+1):
#             count = 0
#             if map[i][j] == 'X':
#                 if map[i-1][j] == '.':    # 상
#                     count += 1
#                 if map[i+1][j] == '.':    # 하
#                     count += 1
#                 if map[i][j-1] == '.':    # 좌
#                     count += 1
#                 if map[i][j+1] == '.':    # 우
#                     count += 1
                
#                 if count >= 3:
#                     ans_str += ['.']
#                 else:
#                     ans_str += ['X']
#             else:
#                 ans_str += ['.']
#         answer.append(ans_str)

# def del_sea(a,b,c):
#     for j in range(a,b,c):
#         for i in range(len(answer)):
#             if answer[i][j] == 'X':
#                 return
#         else:
#             for k in range(len(answer)):
#                 answer[k][j] = 's'

# def del_sea2():
#     for j in range(len(answer[0])):
#         for i in range(len(answer)-1,-1,-1):
#             if answer[i][j] == 'X':
#                 return
#         else:
#             answer[i][len(answer)-1] = 's'

# def del_sea4():
#     for i in range(len(answer)):
#         for j in range(len(answer[0])):
#             if answer[i][j] == 'X':
#                 return
#         else:
#             for k in range(len(answer[0])):
#                 answer[i][k] = 's'

# def del_sea3():
#     for i in range(len(answer)-1,-1,-1):
#         for j in range(len(answer[0])):
#             if answer[i][j] == 'X':
#                 return
#         else:
#             for k in range(len(answer[0])):
#                 answer[i][k] = 's'
            
# del_sea(0,C,1)
# del_sea(C-1,-1,-1)
# del_sea3()
# del_sea4()

# for i in range(len(answer)):
#     for j in range(C):
#         if answer[i][j] != 's':
#             print(answer[i][j], end='')
#     print()



# """
# 5 3
# ...
# .X.
# .X.
# .X.
# ...

# """