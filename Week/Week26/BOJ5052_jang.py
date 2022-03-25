tc = int(input())

def solve(n):
    for i in range(n-1):
        if book[i] == book[i+1][0 : len(book[i])]:
            print("NO")
            return
    print("YES")

for _ in range(tc):
    n = int(input())
    book = []
    for _ in range(n):
        book.append(input())
    book.sort()
    solve(n)
