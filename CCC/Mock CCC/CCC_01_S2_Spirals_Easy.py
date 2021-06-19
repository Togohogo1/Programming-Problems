a, b = int(input()), int(input())

r, c, move, i = 4, 4, 0, 0
flag = True

board = [[0 for i in range(10)] for i in range(10)]

board[r][c] = a
a += 1


def reformat(li):
    s = ""

    max_col = []
    temp_col = []

    for i in range(10):
        for j in range(10):
            if li[j][i] != 0:
                temp_col.append(len(str(li[j][i])))
            else:
                temp_col.append(-1)

        max_col.append(max(temp_col))

        temp_col = []

    for i in range(10):
        for j in range(10):
            if max_col[i] != -1:
                if li[j][i] == 0:
                    li[j][i] = max_col[i] * " "
                elif len(str(li[j][i])) < max_col[i]:
                    li[j][i] = (max_col[i] - len(str(li[j][i]))) * " " + str(str(li[j][i]))
                elif len(str(li[j][i])) == max_col[i]:
                    li[j][i] = str(li[j][i])

    for i in range(10):
        for j in range(10):
            if li[i][j] != 0:
                s += li[i][j] + " "

        if set(s) != {" "}:
            print(s[:-1])

        s = ""


while True:
    if flag == False:
        break

    move += 1

    for i in range(move):
        if a == b + 1:
            flag = False
            break

        if move % 2 == 0:
            r -= 1
        elif move % 2 == 1:
            r += 1

        board[r][c] = a
        a += 1

    for i in range(move):
        if a == b + 1:
            flag = False
            break

        if move % 2 == 0:
            c -= 1
        elif move % 2 == 1:
            c += 1

        board[r][c] = a
        a += 1

    i += 1

reformat(board)
