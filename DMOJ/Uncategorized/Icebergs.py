from collections import deque


def psa_2d(grid):
    grid_w = len(grid[0]) + 1
    grid_h = len(grid) + 1

    query = [[0]*(grid_w) for i in range(grid_h)]
    query[1][1] = grid[0][0]

    for i in range(1, grid_w):
        query[1][i] = query[1][i-1] + grid[0][i-1]

    for i in range(1, grid_h):
        query[i][1] = query[i-1][1] + grid[i-1][0]

    for i in range(2, grid_h):
        for j in range(2, grid_w):
            query[i][j] = query[i - 1][j] + query[i][j-1] - query[i-1][j-1] + grid[i-1][j-1]

    return query


def bfs(start_r, start_c, end_r, end_c):
    if (ship_l, ship_w) == (ocean_r, ocean_c):
        if ocean_map[0][0] + ocean_map[ocean_r][ocean_r] - ocean_map[0][ocean_c] - ocean_map[ocean_r][0] != 0:
            return -1

    dist = 0
    reached = False

    visited = [[0]*end_c for _ in range(end_r)]

    queue_r = deque()
    queue_c = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_r.append(start_r)
    queue_c.append(start_c)

    visited[start_r][start_c] = 1

    new_r, new_c = start_r, start_c

    while queue_r:
        if reached:
            break

        for _ in range(len(queue_r)):
            curr_r = queue_r.popleft()
            curr_c = queue_c.popleft()

            if (curr_r, curr_c) == (end_r-1, end_c-1):
                reached = True
                return dist

            for change_r, change_c in zip(dir_r, dir_c):
                new_r = curr_r + change_r
                new_c = curr_c + change_c

                if not 0 <= new_r < end_r or not 0 <= new_c < end_c:
                    continue
                elif ocean_map[new_r+ship_l][new_c+ship_w] + ocean_map[new_r][new_c] - ocean_map[new_r+ship_l][new_c] - ocean_map[new_r][new_c+ship_w] != 0:
                    continue
                elif visited[new_r][new_c] == 1:
                    continue

                queue_r.append(new_r)
                queue_c.append(new_c)

                visited[new_r][new_c] = 1

        dist += 1

    else:
        return -1


ocean_r, ocean_c = map(int, input().split())
ship_l, ship_w = map(int, input().split())

ocean = [[[1, 0][i == "."] for i in input()] for _ in range(ocean_r)]
ocean_map = psa_2d(ocean)

print(bfs(0, 0, ocean_r-ship_l+1, ocean_c-ship_w+1))
