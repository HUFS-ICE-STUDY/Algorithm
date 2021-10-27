import sys

input = sys.stdin.readline

route = [input().rstrip() for _ in range(36)]
route_set = set(route)

for i in range(35):
    start = route[i]
    end = route[i+1]

    if(abs(ord(start[0]) - ord(end[0])) == 2 and abs(int(start[1]) - int(end[1])) == 1) or (abs(ord(start[0]) - ord(end[0])) == 1 and abs(int(start[1]) - int(end[1])) == 2):
        pass
    else:
        print('Invalid')
        exit(0)

start = route[0]
end = route[35]

if(((abs(ord(start[0]) - ord(end[0])) == 2 and abs(int(start[1]) - int(end[1])) == 1) or (abs(ord(start[0]) - ord(end[0])) == 1 and abs(int(start[1]) - int(end[1])) == 2)) and len(route_set) == 36):
    print('Valid')
else:
    print('Invalid')
