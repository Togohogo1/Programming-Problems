from collections import deque


def Flocate():
    flood = []
    for i in range(R):
        for j in range(C):
            if forest[i][j] == "*":
                flood.append([i, j])
    return flood


def Slocate():
    for i in range(R):
        for j in range(C):
            if forest[i][j] == "S":
                return [i, j]


def bfs(start_r, start_c, floodlist, height, width):
    dist = 0
    reached = False

    tempforest = forest.copy()

    visited = [[False]*width for _ in range(height)]
    Fvisited = [[False]*width for _ in range(height)]

    queue_r = deque()
    queue_c = deque()
    Fqueue_r = deque()
    Fqueue_c = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_r.append(start_r)
    queue_c.append(start_c)
    visited[start_r][start_c] = True

    for i in range(len(floodlist)):
        Fqueue_r.append(floodlist[i][0])
        Fqueue_c.append(floodlist[i][1])
        Fvisited[floodlist[i][0]][floodlist[i][1]] = True

    new_r, new_c = start_r, start_c

    while queue_r:
        # Flooding of each of the flooded fields
        for _ in range(len(Fqueue_r)):
            Fcurr_r = Fqueue_r.popleft()
            Fcurr_c = Fqueue_c.popleft()

            for change_r, change_c in zip(dir_r, dir_c):
                Fnew_r = Fcurr_r + change_r
                Fnew_c = Fcurr_c + change_c

                if not 0 <= Fnew_r < height or not 0 <= Fnew_c < width:
                    continue
                elif Fvisited[Fnew_r][Fnew_c]:
                    continue
                elif tempforest[Fnew_r][Fnew_c] in {"X", "D", "S"}:
                    continue

                Fqueue_r.append(Fnew_r)
                Fqueue_c.append(Fnew_c)

                Fvisited[Fnew_r][Fnew_c] = True
                tempforest[Fnew_r][Fnew_c] = "*"

        if reached:
            break

        # Movements of the painter and three little hedgehogs
        for _ in range(len(queue_r)):

            curr_r = queue_r.popleft()
            curr_c = queue_c.popleft()

            if forest[curr_r][curr_c] == "D":
                reached = True
                return dist

            for change_r, change_c in zip(dir_r, dir_c):
                new_r = curr_r + change_r
                new_c = curr_c + change_c

                if not 0 <= new_r < height or not 0 <= new_c < width:
                    continue
                elif visited[new_r][new_c]:
                    continue
                elif tempforest[new_r][new_c] in {"X", "*"}:
                    continue

                queue_r.append(new_r)
                queue_c.append(new_c)

                visited[new_r][new_c] = True

        dist += 1

    else:
        return "KAKTUS"

R, C = map(int, input().split())

forest = []

for i in range(R):
    forest.append(list(input()))

board = [[0]*R for _ in range(C)]

print(bfs(Slocate()[0], Slocate()[1], Flocate(), R, C))
