arr = []
for i in range(9):
    arr.append(int(input()))

arr = sorted(arr)
diff = sum(arr) - 100

def find_jjap():        
    for i in range(9):
        temp = arr[i]
        for j in range(i+1,9):
            if arr[j] == diff - temp:
                return temp, arr[j]

a,b = find_jjap()

for i in range(9):
    if arr[i] == a or arr[i] == b:
        continue
    print(arr[i])