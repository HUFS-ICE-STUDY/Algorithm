import sys

input = sys.stdin.readline

n = int(input())

prime_num = [True]*(n+1)
prime_num[1] = False
cnt = 0

for i in range(2, int(n**0.5)+1):
    if(prime_num[i]):
        for j in range(i+i, n+1, i):
            prime_num[j] = False

prime = [i for i in range(2, n+1) if prime_num[i]]

num = 0
end = 0

for start in range(len(prime)):
    while(num < n and end < len(prime)):
        num += prime[end]
        end += 1

    if(num == n):
        cnt += 1

    num -= prime[start]

print(cnt)
