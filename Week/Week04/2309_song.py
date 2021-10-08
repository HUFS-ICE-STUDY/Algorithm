arr = []
for i in range(9):
    arr.append(int(input()))

sum = 0
for i in arr:
    sum += i
    for j in arr[1:]:
        sum += j
        for k in arr[2:]:
            sum += k
            for l in arr[3:]:
                sum += l
                for m in arr[4:]:
                    sum += m
                    for n in arr[5:]:
                        sum += n
                        for o in arr[6:]:
                            sum += o
                            if sum==100:
                                for p in sorted([i, j, k, l, m, n, o]):
                                    print(p)
                                exit()
                            sum -= o
                        sum -= n
                    sum -= m
                sum -= l
            sum -= k
        sum -= j
    sum -= i