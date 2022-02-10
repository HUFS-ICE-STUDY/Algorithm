n = int(input())
arr = list(map(int,input().split()))
arr.reverse()

denominator = arr[0] # 분모
numerator = 1   # 분자

for i in range(1,n):
    temp = denominator
    denominator = denominator*arr[i] + numerator
    numerator = temp
    
print(denominator-numerator, denominator)