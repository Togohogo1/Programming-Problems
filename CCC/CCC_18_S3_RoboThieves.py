from collections import deque


def bfs(start_r, start_c, height, width):
    # Robot spawns right next to the camera
    if (start_r, start_c) in block:
        return

    dist = 0
    conveyor = False

    queue_r = deque()
    queue_c = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_r.append(start_r)
    queue_c.append(start_c)
    visited[start_r][start_c] = 0

    new_r, new_c = start_r, start_c

    while queue_r:
        for _ in range(len(queue_r)):
            curr_r = queue_r.popleft()
            curr_c = queue_c.popleft()

            for change_r, change_c in zip(dir_r, dir_c):
                new_r = curr_r + change_r
                new_c = curr_c + change_c
                conveyor = False

                if not 0 <= new_r < height or not 0 <= new_c < width:
                    continue

                elif visited[new_r][new_c] > -1:
                    continue

                elif (new_r, new_c) in block:
                    continue

                if board[new_r][new_c] in "UDRL":
                    visited[new_r][new_c] = 0

                    # Set for loops
                    temp = set()
                    temp.add((new_r, new_c))

                    while True:
                        if board[new_r][new_c] == "U":
                            new_r -= 1
                        elif board[new_r][new_c] == "D":
                            new_r += 1
                        elif board[new_r][new_c] == "R":
                            new_c += 1
                        elif board[new_r][new_c] == "L":
                            new_c -= 1

                        # Check for loop
                        if (new_r, new_c) not in temp:
                            temp.add((new_r, new_c))
                        else:
                            conveyor = True
                            break

                        # End of conveyor
                        if (new_r, new_c) in block:
                            conveyor = True
                            break
                        elif board[new_r][new_c] == ".":
                            break

                if conveyor:
                    continue

                queue_r.append(new_r)
                queue_c.append(new_c)

                # Visited could be reached multiple times with conveyor
                if visited[new_r][new_c] == -1:
                    visited[new_r][new_c] = dist + 1

        dist += 1


start_r, start_c = -1, -1

board = []
ends = []
block = set()
cams = set()

rows, cols = map(int, input().split())

visited = [[-1]*cols for _ in range(rows)]

for i in range(rows):
    board.append(list(input()))

for i in range(rows):
    for j in range(cols):
        if board[i][j] == "S":
            start_r, start_c = i, j

        if board[i][j] == "C":
            cams.add((i, j))
            block.add((i, j))

        if board[i][j] == ".":
            ends.append((i, j))

        # Cameras are considered walls
        if board[i][j] == "W":
            block.add((i, j))

# Places where the cameras can see
for r, c in cams:
    for j in range(1, c+1):
        if board[r][c-j] == "W":
            break

        if board[r][c-j] not in "UDRL":
            block.add((r, c-j))

    for j in range(1, cols-c):
        if board[r][c+j] == "W":
            break

        if board[r][c+j] not in "UDRL":
            block.add((r, c+j))

    for j in range(1, r+1):
        if board[r-j][c] == "W":
            break

        if board[r-j][c] not in "UDRL":
            block.add((r-j, c))

    for j in range(1, rows-r):
        if board[r+j][c] == "W":
            break

        if board[r+j][c] not in "UDRL":
            block.add((r+j, c))

bfs(start_r, start_c, rows, cols)

for r, c in ends:
    print(visited[r][c])
