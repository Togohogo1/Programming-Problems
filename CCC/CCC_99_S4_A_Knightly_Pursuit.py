from collections import deque


def pawn(pawn_r, num_of_rows):
    arr_pawn = [0]*num_of_rows
    arr_pawn[pawn_r] = 1

    for i in range(num_of_rows - 1):
        if arr_pawn[i] > 0:
            arr_pawn[i+1] = arr_pawn[i] + 1

    return arr_pawn


def col_extract(visited, pawn_c):
    arr_knight = []

    for j in range(num_of_rows):
        arr_knight.append(visited[j][pawn_c-1])

    return arr_knight


def bfs(board, start_r, start_c):
    filled = 0

    queue_r = deque()
    queue_c = deque()

    visited = [[0 for i in range(num_of_cols)] for j in range(num_of_rows)]

    queue_r.append(start_r)
    queue_c.append(start_c)

    visited[start_r][start_c] = 1

    while len(queue_r) > 0:
        current_pos_r = queue_r.popleft()
        current_pos_c = queue_c.popleft()

        if filled == num_of_cols*num_of_rows - 1:
            return visited

        r_move = [2, 2, -2, -2, 1, 1, -1, -1]
        c_move = [1, -1, 1, -1, 2, -2, 2, -2]

        for i in range(8):
            new_pos_r = current_pos_r + r_move[i]
            new_pos_c = current_pos_c + c_move[i]

            if new_pos_r < 0 or new_pos_c < 0:
                continue
            elif new_pos_r >= num_of_rows or new_pos_c >= num_of_cols:
                continue
            elif visited[new_pos_r][new_pos_c] != 0:
                continue

            visited[new_pos_r][new_pos_c] = visited[current_pos_r][current_pos_c] + 1
            filled += 1

            queue_r.append(new_pos_r)
            queue_c.append(new_pos_c)

    else:
        return visited


for i in range(int(input())):
    num_of_rows, num_of_cols = int(input()), int(input())
    pawn_r, pawn_c = int(input()), int(input())
    knight_r, knight_c = int(input()), int(input())

    win, lose = False, True

    board = [["." for i in range(num_of_cols)] for j in range(num_of_rows)]
    pawn_move = pawn(pawn_r-1, num_of_rows)[pawn_r-1:]
    knight_move = col_extract(
        bfs(board, knight_r-1, knight_c-1), pawn_c)[pawn_r-1:]

    # If the board has width or length 3 or more
    for i in range(len(knight_move)):
        if pawn_move[i] != knight_move[i] != 0 and num_of_cols != 2 or num_of_rows != 2:
            if pawn_move[i] == knight_move[i]:
                print(f"Win in {i} knight move(s).")
                win, lose = True, False
                break

    # If the board has a dimention of 2
    else:
        if num_of_cols == 2 or num_of_rows == 2:
            for i in range(len(knight_move)):
                if pawn_move[i] != knight_move[i] != 0:
                    # %, when the knight visits a visited square
                    # This is not needed when dimentions are >= 3
                    if pawn_move[i] % knight_move[i] == 0:
                        print(f"Win in {i} knight move(s).")
                        win, lose = True, False
                        break

    if not win:
        for i in range(len(knight_move)-1):
            if pawn_move[i] != 0 or knight_move[i+1] != 0:
                if pawn_move[i] == knight_move[i+1]:
                    print(f"Stalemate in {i} knight move(s).")
                    break
        else:
            print(f"Loss in {i} knight move(s).")
