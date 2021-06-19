rect_w = int(input())
rect_h = int(input())
cut_w = int(input())
cut_h = int(input())
steps = int(input())

board = [[0 for i in range(rect_w)] for i in range(rect_h)]

for i in range(rect_h):
    for j in range(rect_w):
        if i < cut_h and j < cut_w:
            board[i][j] = 1
        if i < cut_h and j >= rect_w - cut_w:
            board[i][j] = 1
        if i >= rect_h - cut_h and j < cut_w:
            board[i][j] = 1
        if i >= rect_h - cut_h and j >= rect_w - cut_w:
            board[i][j] = 1

r = 0
c = cut_w
idx = 0

mr = [0, 1, 0, -1]
mc = [1, 0, -1, 0]
board[r][c] = 2

for i in range(steps):
    try:
        if (c == rect_w-1 or board[r][c+1] != 0) and idx == 0:
            idx = 1
        elif (r == rect_h-1 or board[r+1][c] != 0) and idx == 1:
            idx = 2
        elif (c == 0 or board[r][c-1] != 0) and idx == 2:
            idx = 3
        elif (r == 0 or board[r-1][c] != 0) and idx == 3:
            idx = 0

        if board[r-1][c] == 2 and board[r-1][c+1] != 0 and board[r][c+1] == 0:
            idx = 0
        elif board[r][c+1] == 2 and board[r+1][c+1] != 0 and board[r+1][c] == 0:
            idx = 1
        elif board[r+1][c] == 2 and board[r+1][c-1] != 0 and board[r][c-1] == 0:
            idx = 2
        elif board[r][c-1] == 2 and board[r-1][c-1] != 0 and board[r-1][c] == 0:
            idx = 3
    except:
        pass

    r += mr[idx % 4]
    c += mc[idx % 4]

    if board[r][c] != 0:
        if idx == 1:
            r -= 1
        elif idx == 2:
            c += 1
        elif idx == 3:
            r += 1
        elif idx == 0:
            c -= 1
        break

    board[r][c] = 2

print(c+1)
print(r+1)
