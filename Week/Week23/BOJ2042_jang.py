import sys
input = sys.stdin.readline

arr = []
tree = [0] * 5000000

n,m,k = map(int,input().split())

for _ in range(n):
    arr.append(int(input()))
    
def init(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    else:
        tree[node] = init(node*2, start, (start+end)//2) + init(node*2+1, (start+end)//2 + 1, end)
        return tree[node]



def treeSum(node, start, end, left, right):
    if left > end or right < start:
        return 0
    
    if left <= start and right >= end:
        return tree[node]

    return treeSum(node*2, start, (start+end)//2, left, right) + treeSum(node*2+1, (start+end)//2 + 1, end, left, right)

def treeUpdate(node, start, end, index, change):
    if index < start or index > end:
        return
    
    tree[node] += change

    if start != end:
        treeUpdate(node*2, start, (start+end)//2, index, change)
        treeUpdate(node*2+1, (start+end)//2 + 1, end, index, change)


init(1,0,n-1)

for _ in range(m+k):
    a,b,c = map(int,input().split())
    
    if a == 1:
        b -= 1
        change = c - arr[b]
        arr[b] = c
        treeUpdate(1, 0, n-1, b, change)
    elif a == 2:
        print(treeSum(1, 0, n-1, b-1, c-1))


