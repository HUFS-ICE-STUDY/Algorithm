def prime_list(n):
    # 에라토스테네스의 체 : n개 요소에 True 설정(소수로 간주)
    sieve = [True]*n

    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:           # i가 소수인 경우 
            for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False

    # 소수 목록 산출
    return [i for i in range(2, n) if sieve[i] == True]

n = int(input())
arr = prime_list(4000000)

sum = 0
start = 0
end = 0
cnt = 0
while True:
    if sum >= n:
        if sum == n:
            cnt +=  1
        sum -= arr[start]
        start += 1
    elif end == len(arr):
        break
    else:
        sum += arr[end]
        end += 1

print(cnt)