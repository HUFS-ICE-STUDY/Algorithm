import sys 
sys.setrecursionlimit(10**6)

n = int(input())
equation = []
for item in input():
    if item == '+' or item == '-' or item == '*':
        equation.append(item)
    else:
        equation.append(int(item))

def cal_queue(queue):
    result = queue[0]
    for i in range(0,len(queue)-2,2):
        result = calculate(result, queue[i+2], queue[i+1])
    return result

def calculate(left,right,op):
    if op == '+':
        return int(left)+int(right)
    elif op == '-':
        return int(left)-int(right)
    else:
        return int(left)*int(right)

def solution(i, queue):
    if i == n-1:
        no_br_q = queue + [equation[i]]
        return cal_queue(no_br_q)
    if i == n-3:    # 한번 더 가거나 괄호 치거나
        no_br_q = queue + [equation[i],equation[i+1]]

        temp = calculate(equation[i], equation[i+2], equation[i+1])
        br_q = queue + [temp]
        return max(solution(i+2, no_br_q), cal_queue(br_q))
    
    # 괄호 없는 경우
    no_br_q = queue + [equation[i], equation[i+1]]
    # 괄호 넣는 경우
    temp = calculate(equation[i], equation[i+2], equation[i+1])
    br_q = queue + [temp, equation[i+3]]    # 괄호 내용 결과값과 연산자를 더한다.
    
    return max(solution(i+2, no_br_q), solution(i+4, br_q))

print(solution(0,[]))