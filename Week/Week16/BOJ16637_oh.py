import sys

input = sys.stdin.readline


def solution(i):
    global result
    global able

    result = max(result, calc())

    for k in range(i, len(s)//2):
        able[k] = False
        solution(k+2)
        able[k] = True


def calc():
    num, op = [], []
    arr = list(s)

    for i in range(len(able)):
        if(able[i]):
            num.append(int(arr[2*i]))
            op.append(arr[2*i + 1])
        else:
            temp = int(arr[2*i])
            if(arr[2*i + 1] == '+'):
                temp += int(arr[2*(i+1)])
            elif(arr[2*i + 1] == '-'):
                temp -= int(arr[2*(i+1)])
            else:
                temp *= int(arr[2*(i+1)])
            arr[2*(i+1)] = temp

    num.append(int(arr[-1]))

    temp = num[0]

    for i in range(len(op)):
        if(op[i] == '+'):
            temp += num[i+1]
        elif(op[i] == '-'):
            temp -= num[i+1]
        else:
            temp *= num[i+1]

    return temp


n = int(input())

s = input().rstrip()
able = [True]*(len(s) // 2)
result = -sys.maxsize

solution(0)

print(result)
