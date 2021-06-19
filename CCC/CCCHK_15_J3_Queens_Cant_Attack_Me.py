board_size, queens = map(int, input().split())

board = [[1] * board_size for i in range(board_size)]

for i in range(queens):
    x, y = map(int, input().split())

    x -= 1
    y -= 1

    for i in range(board_size):
        board[i][y] = 0
        board[x][i] = 0

    for i in range(1, min(x, y) + 1):
        board[x-i][y-i] = 0

    for i in range(1, board_size - max(x, y)):
        board[x+i][y+i] = 0

    for i in range(1, board_size - min(x, y)):
        try:
            if x - i >= 0:
                board[x-i][y+i] = 0
        except:
            pass

    for i in range(1, board_size - min(x, y)):
        try:
            if y - i >= 0:
                board[x+i][y-i] = 0
        except:
            pass

print(sum(sum(board, [])))
