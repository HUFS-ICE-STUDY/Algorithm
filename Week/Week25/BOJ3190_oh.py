class Snake():
    def __init__(self, n):
        self.row = 0
        self.col = 0
        self.size = n
        self.time = 0
        self.direction = 0
        self.gameover = False
        self.apple = []
        self.snakepos = [(0, 0)]

    def move(self, x, c):
        if(self.gameover):
            return

        k = x - self.time

        for _ in range(k):
            if(self.direction == 0):
                if(self.col+1 >= self.size or ((self.row, self.col+1) != 0 and (self.row, self.col+1) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row, self.col+1))

                    if((self.row, self.col+1) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row, self.col+1)))
                    else:
                        self.snakepos.pop(0)

                    self.col += 1
                    self.time += 1
            elif(self.direction == 1):
                if(self.row+1 >= self.size or ((self.row+1, self.col) != 0 and (self.row+1, self.col) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row+1, self.col))

                    if((self.row+1, self.col) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row+1, self.col)))
                    else:
                        self.snakepos.pop(0)

                    self.row += 1
                    self.time += 1
            elif(self.direction == 2):
                if(self.col-1 < 0 or ((self.row, self.col-1) != 0 and (self.row, self.col-1) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row, self.col-1))

                    if((self.row, self.col-1) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row, self.col-1)))
                    else:
                        self.snakepos.pop(0)

                    self.col -= 1
                    self.time += 1
            else:
                if(self.row-1 < 0 or ((self.row-1, self.col) != 0 and (self.row-1, self.col) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row-1, self.col))

                    if((self.row-1, self.col) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row-1, self.col)))
                    else:
                        self.snakepos.pop(0)

                    self.row -= 1
                    self.time += 1

            print(self.snakepos)
            print(self.time)

        if(c == 'L'):
            self.direction = (self.direction + 3) % 4
        else:
            self.direction = (self.direction + 1) % 4

    def appleIdx(self, i, j):
        self.apple.append((i, j))

    def isApple(self, i, j):
        for t in self.snakepos:
            if(t == (i, j)):
                return True
        return False

    def lastMove(self):
        while(True):
            if(self.direction == 0):
                if(self.col+1 >= self.size or ((self.row, self.col+1) != 0 and (self.row, self.col+1) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row, self.col+1))

                    if((self.row, self.col+1) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row, self.col+1)))
                    else:
                        self.snakepos.pop(0)

                    self.col += 1
                    self.time += 1
            elif(self.direction == 1):
                if(self.row+1 >= self.size or ((self.row+1, self.col) != 0 and (self.row+1, self.col) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row+1, self.col))

                    if((self.row+1, self.col) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row+1, self.col)))
                    else:
                        self.snakepos.pop(0)

                    self.row += 1
                    self.time += 1
            elif(self.direction == 2):
                if(self.col-1 < 0 or ((self.row, self.col-1) != 0 and (self.row, self.col-1) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row, self.col-1))

                    if((self.row, self.col-1) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row, self.col-1)))
                    else:
                        self.snakepos.pop(0)

                    self.col -= 1
                    self.time += 1
            else:
                if(self.row-1 < 0 or ((self.row-1, self.col) != 0 and (self.row-1, self.col) in self.snakepos)):
                    self.gameover = True
                    return
                else:
                    self.snakepos.append((self.row-1, self.col))

                    if((self.row-1, self.col) in self.apple):
                        self.apple.pop(self.apple.index(
                            (self.row-1, self.col)))
                    else:
                        self.snakepos.pop(0)

                    self.row -= 1
                    self.time += 1


n = int(input())
k = int(input())

snakeGame = Snake(n)

for _ in range(k):
    i, j = map(int, input().split(' '))

    snakeGame.appleIdx(i-1, j-1)

l = int(input())

for _ in range(l):
    x, c = map(str, input().split(' '))

    snakeGame.move(int(x), c)

snakeGame.lastMove()

print(snakeGame.time + 1)
