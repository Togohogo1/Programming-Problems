from collections import deque


def bfs(start_r, start_c, end_r, end_c, height, width):
    reached = False

    visited = [[0]*width for _ in range(height)]
    queue_r = deque()
    queue_c = deque()

    dir_r = [1, 0]
    dir_c = [0, 1]

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

            if (curr_r, curr_c) == (end_r, end_c):
                reached = True
                return visited[end_r][end_c]

            for change_r, change_c in zip(dir_r, dir_c):
                new_r = curr_r + change_r
                new_c = curr_c + change_c

                if not 0 <= new_r < height or not 0 <= new_c < width:
                    continue
                elif visited[new_r][new_c]:
                    continue
                elif [new_r, new_c] in cats:
                    continue

                queue_r.append(new_r)
                queue_c.append(new_c)

                visited[new_r][new_c] = visited[new_r-1][new_c] + visited[new_r][new_c-1]

    return visited[end_r][end_c]


cats = []
board = [[0 for i in range(25)] for i in range(25)]

R, C = map(int, input().split())
cat = int(input())

for i in range(cat):
    cr, cc = map(int, input().split())
    cats.append([cr-1, cc-1])

print(bfs(0, 0, R-1, C-1, R, C))
