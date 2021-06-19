def check(board):
    o_count = 0
    x_count = 0

    for i in range(3):
        if board[0][i] == board[1][i] == board[2][i] == "O":
            o_count += 1
        elif board[i][0] == board[i][1] == board[i][2] == "O":
            o_count += 1
        elif board[0][i] == board[1][i] == board[2][i] == "X":
            x_count += 1
        elif board[i][0] == board[i][1] == board[i][2] == "X":
            x_count += 1

    if board[0][0] == board[1][1] == board[2][2] == "O":
        o_count += 1
    elif board[0][2] == board[1][1] == board[2][0] == "O":
        o_count += 1
    elif board[0][0] == board[1][1] == board[2][2] == "X":
        x_count += 1
    elif board[0][2] == board[1][1] == board[2][0] == "X":
        x_count += 1

    return x_count, o_count


board = []

for i in range(3):
    board.append(list(input()))

if check(board)[0] >= 1 and check(board)[1] == 0:
    print("Timothy")
elif check(board)[0] == 0 and check(board)[1] >= 1:
    print("Griffy")
elif check(board)[0] == check(board)[1] == 0:
    print("Tie")
else:
    print("Error, redo")
