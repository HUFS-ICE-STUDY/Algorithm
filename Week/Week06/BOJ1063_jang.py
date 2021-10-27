king, stone, n = map(str, input().split())

dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, -1, 1, 1, 1, -1, -1]

move = ['R', 'L', 'B', 'T', 'RT', 'LT', 'RB', 'LB']

king_x = ord(king[0]) - ord('A')
king_y = int(king[1]) - 1

stone_x = ord(stone[0]) - ord('A')
stone_y = int(stone[1]) - 1

for _ in range(int(n)):
    d = move.index(input())
    nx = king_x + dx[d]
    ny = king_y + dy[d]
    if nx < 0 or ny < 0 or nx > 7 or ny > 7:
        continue
    if nx == stone_x and ny == stone_y:
        stone_nx = stone_x + dx[d]
        stone_ny = stone_y + dy[d]
        if stone_nx < 0 or stone_ny < 0 or stone_nx > 7 or stone_ny > 7:
            continue
        stone_x, stone_y = stone_nx, stone_ny
    king_x, king_y = nx, ny

print(f'{chr(king_x + ord("A"))}{king_y + 1}')
print(f'{chr(stone_x + ord("A"))}{stone_y + 1}')