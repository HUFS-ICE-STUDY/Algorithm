def Operation(bit):
    cnt = 1
    while True:
        # NOT 연산
        ans = ""
        arr = [i for i in bit]
        for i in arr:
            if i=="0": ans += "1"
            else: ans += "0"
        
        # 산술 더하기 연산
        ans = int('0b'+ans, 2)+1

        # AND 연산
        ans = int('0b'+bit, 2) & ans

        # 산술 빼기 연산
        ans = int('0b'+bit, 2)-ans

        if ans != 0:
            bit = format(ans, 'b')
            cnt += 1
        else:
            print(cnt)
            break

n = int(input())
bit = input()

if int('0b'+bit, 2)==0: print(0)
else: Operation(bit)