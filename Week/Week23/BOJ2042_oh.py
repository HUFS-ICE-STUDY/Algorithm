import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())


def init(node, start, end):
    mid = (start + end) // 2

    if(start == end):
        tree[node] = arr[start]
        return tree[node]

    tree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end)
    return tree[node]

# 세그먼트 트리의 값들을 업데이트
# start, end -> 시작, 끝 인덱스, i -> 수정할 값, idx -> 구간 함


def update(node, start, end, i, idx):
    mid = (start + end) // 2

    if(idx < start or idx > end):
        return

    tree[node] += i

    if(start != end):
        update(node*2, start, mid, i, idx)
        update(node*2 + 1, mid+1, end, i, idx)

# left, right 사이의 구간 합을 구해주는 함수


def interval_sum(node, start, end, left, right):
    mid = (start + end) // 2

    if(left > end or right < start):
        return 0

    if(left <= start and right >= end):
        return tree[node]

    return interval_sum(node*2, start, mid, left, right) + interval_sum(node*2+1, mid+1, end, left, right)


arr = [int(input()) for _ in range(n)]

implement = [list(map(int, input().split())) for _ in range(m+k)]

tree = [0]*4000001

init(1, 0, n-1)

for i, a, b in implement:
    if(i == 1):
        update(1, 1, n, b-arr[a-1], a)
        arr[a-1] = b
    else:
        print(interval_sum(1, 1, n, a, b))
