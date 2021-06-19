count = 0
board = []

for i in range(6):
    b2 = []

    for j in range(7):
        c = input()
        if c != "":
            b2.append(c)
        if i == 5 and j == 5:
            break

    board.append(b2)

for i in range(6):
    for j in range(6):
        for k in range(6):
            try:
                if board[i][j][k] == board[i][j][k+1] == board[i][j][k+2] == board[i][j][k+3] == "R":
                    count += 1
                if board[i][k][j] == board[i][k+1][j] == board[i][k+2][j] == board[i][k+3][j] == "R":
                    count += 1
                if board[k][i][j] == board[k+1][i][j] == board[k+2][i][j] == board[k+3][i][j] == "R":
                    count += 1
            except IndexError:
                pass

if count > 0:
    print(count)
else:
    print("lost")
