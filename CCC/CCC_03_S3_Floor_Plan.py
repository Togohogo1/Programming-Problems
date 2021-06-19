from collections import deque


def bfs(start_r, start_c, height, width):
    count = 0

    queue_r = deque()
    queue_c = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_r.append(start_r)
    queue_c.append(start_c)

    new_r, new_c = start_r, start_c

    while queue_r:

        for _ in range(len(queue_r)):

            curr_r = queue_r.popleft()
            curr_c = queue_c.popleft()

            for change_r, change_c in zip(dir_r, dir_c):
                new_r = curr_r + change_r
                new_c = curr_c + change_c

                if not 0 <= new_r < height or not 0 <= new_c < width:
                    continue
                elif board[new_r][new_c] == "I":
                    continue

                queue_r.append(new_r)
                queue_c.append(new_c)

                board[new_r][new_c] = "I"
                count += 1

    return count


tiles = int(input())
rows = int(input())
cols = int(input())

fill = 0

board = []
rooms = []

for i in range(rows):
    board.append(list(input()))

for i in range(rows):
    for j in range(cols):
        if board[i][j] == ".":
            rooms.append(bfs(i, j, rows, cols))

rooms.sort(reverse=True)

if not rooms:
    print(f"0 rooms, {tiles} square metre(s) left over")
else:
    if rooms[-1] == 0:
        rooms[-1] += 1

    for i in rooms:
        tiles -= i
        fill += 1

        if tiles < 0:
            fill -= 1
            tiles += i
            break

    if fill == 1:
        print(f"{fill} room, {tiles} square metre(s) left over")
    else:
        print(f"{fill} rooms, {tiles} square metre(s) left over")
