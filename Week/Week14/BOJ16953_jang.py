a,b = map(int,input().split())

def solution(a,b):
    count = 1
    while True:
        if a==b:
            return count

        elif b%10 == 1:
            b = b//10
            count += 1
            continue
        else:
            if b%2 == 1 or a>b:
                return -1
            b = b//2
            count += 1
            continue
        
print(solution(a,b))