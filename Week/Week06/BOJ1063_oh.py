import sys

input = sys.stdin.readline

king, stone, k = input().rstrip().split()


def pos(y, x):
    if(0 <= y < 8 and 0 <= x < 8):
        return True
    return False


arr = [input().rstrip() for _ in range(int(k))]
move = {'R': (1, 0), 'L': (-1, 0), 'B': (0, -1), 'T': (0, 1),
        'RT': (1, 1), 'LT': (-1, 1), 'RB': (1, -1), 'LB': (-1, -1)}

king_y = ord(king[0]) - ord('A')
king_x = int(king[1]) - 1
stone_y = ord(stone[0]) - ord('A')
stone_x = int(stone[1]) - 1

for c in arr:
    temp_y = king_y + move[c][0]
    temp_x = king_x + move[c][1]

    if(temp_y == stone_y and temp_x == stone_x):
        y1 = stone_y + move[c][0]
        x1 = stone_x + move[c][1]

        if(pos(y1, x1)):
            stone_y = y1
            stone_x = x1
            king_y = temp_y
            king_x = temp_x
    elif(pos(temp_y, temp_x)):
        king_y = temp_y
        king_x = temp_x

king = chr(king_y + 65) + str(king_x+1)
stone = chr(stone_y + 65) + str(stone_x+1)

print(king)
print(stone)
