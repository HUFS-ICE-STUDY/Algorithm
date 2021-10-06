def check(index):
    global result
    # 최후의 순간에 문자열 길이와 index가 같은 경우
    if len(s) == index:
        result = 1
        return
    if dp[index] != 0:
        return
    dp[index] = 1
    for i in range(len(arr)):
        if len(s[index:]) >= len(arr[i]):
            for j in range(len(arr[i])):
                # arr과 문자열 서로 확인
                if arr[i][j] != s[index+j]:
                    break
            else:
                check(index+len(arr[i]))

s = input()
n = int(input())
arr = []
for i in range(n):
    arr.append(input())
dp = [0]*101
result = 0
check(0)
print(result)