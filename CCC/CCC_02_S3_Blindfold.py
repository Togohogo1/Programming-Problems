board = []
directions = []


def location(r, c, directions):
    fin = []
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    for i in range(4):
        tr, tc = r, c
        rr, cc = i, i

        for j in directions:
            if j == "F":
                tr += dr[(rr) % 4]
                tc += dc[(cc) % 4]

                if tr >= row or tr < 0:
                    break
                if tc >= col or tc < 0:
                    break
                if board[tr][tc] == "X":
                    break

            elif j == "L":
                rr -= 1
                cc -= 1

            elif j == "R":
                rr += 1
                cc += 1

        else:
            fin.append([tr, tc])

    return fin


row = int(input())
col = int(input())

for i in range(row):
    board.append(list(input()))

temp_board = board

m = int(input())

for i in range(m):
    directions.append(input())

for i in range(row):
    for j in range(col):
        if board[i][j] != "X":
            if location(i, j, directions) != []:
                for k in location(i, j, directions):
                    board[k[0]][k[1]] = "*"

for i in board:
    for j in i:
        print(j, end="")

    print()
