from collections import deque

grid_size, beg_ball_r, beg_ball_c, dest_r, dest_c = map(int, input().split())
empty1_r, empty1_c = map(int, input().split())
empty2_r, empty2_c = map(int, input().split())


def bfs(ball_r, ball_c, space_r, space_c, end_r, end_c):
    dist = 0
    reached = False

    visited = [[[[0]*(grid_size) for i in range(grid_size)]
                for i in range(grid_size)] for i in range(grid_size)]

    queue_ball = deque()
    queue_space = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_ball.append([ball_r, ball_c])
    queue_space.append([space_r, space_c])

    visited[ball_r][ball_c][space_r][space_c] = 1

    while queue_ball:
        if reached:
            break

        for _ in range(len(queue_ball)):
            temp_ball_rc = queue_ball.popleft()
            temp_space_rc = queue_space.popleft()

            curr_ball_r = temp_ball_rc[0]
            curr_ball_c = temp_ball_rc[1]
            curr_space_r = temp_space_rc[0]
            curr_space_c = temp_space_rc[1]

            if (curr_ball_r, curr_ball_c) == (end_r, end_c):
                reached = True
                return dist

            for change_r, change_c in zip(dir_r, dir_c):
                new_ball_r = curr_ball_r
                new_ball_c = curr_ball_c
                new_space_r = curr_space_r + change_r
                new_space_c = curr_space_c + change_c

                if (new_ball_r, new_ball_c) == (new_space_r, new_space_c):
                    new_ball_r, new_ball_c = curr_space_r, curr_space_c

                if new_ball_r < 0 or new_ball_c < 0 or new_space_r < 0 or new_space_c < 0:
                    continue
                elif new_ball_r >= grid_size or new_ball_c >= grid_size or new_space_r >= grid_size or new_space_c >= grid_size:
                    continue
                elif visited[new_ball_r][new_ball_c][new_space_r][new_space_c] == 1:
                    continue

                queue_ball.append([new_ball_r, new_ball_c])
                queue_space.append([new_space_r, new_space_c])

                visited[new_ball_r][new_ball_c][new_space_r][new_space_c] = 1

        dist += 1


if (beg_ball_r, beg_ball_c) == (empty1_r, empty1_c):
    print(bfs(empty1_r-1, empty1_c-1, empty2_r-1, empty2_c-1, dest_r-1, dest_c-1))
else:
    print(bfs(empty2_r-1, empty2_c-1, empty1_r-1, empty1_c-1, dest_r-1, dest_c-1))
