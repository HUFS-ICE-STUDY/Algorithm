N = int(input())
answer = []

def solution(num,S,temp):
    if num == N:
        temp.append(num)
        while S:
            temp.append(S.pop())
        answer.append(temp)
        return
    S.append(num)
    solution(num+1,S[:],temp[:])
    while S:
        temp.append(S.pop())
        solution(num+1, S[:], temp[:])
    
solution(1,[],[])
for item in sorted(answer):
    print(*item)