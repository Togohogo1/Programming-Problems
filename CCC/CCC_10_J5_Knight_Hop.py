from collections import deque

board = [["." for i in range(8)] for j in range(8)]


def bfs(board, start_r, start_c, end_r, end_c):
    move_count = 0
    nodes_left_in_layer = 1
    nodes_in_next_layer = 0

    queue_r = deque()
    queue_c = deque()

    len_r = len(board[0])
    len_c = len(board)

    visited = [[0 for i in range(8)] for j in range(8)]

    # The BFS algorithm below
    queue_r.append(start_r)
    queue_c.append(start_c)

    visited[start_r][start_c] = 1

    while len(queue_r) > 0:
        current_pos_r = queue_r.popleft()
        current_pos_c = queue_c.popleft()

        if current_pos_r == end_r and current_pos_c == end_c:
            return move_count

        # Direction vectors for N, S, E, and W
        r_move = [2, 2, -2, -2, 1, 1, -1, -1]
        c_move = [1, -1, 1, -1, 2, -2, 2, -2]

        for i in range(8):
            new_pos_r = current_pos_r + r_move[i]
            new_pos_c = current_pos_c + c_move[i]

            if new_pos_r < 0 or new_pos_c < 0:  # Skip if the position outside of grid
                continue
            elif new_pos_r >= len_c or new_pos_c >= len_r:
                continue
            elif visited[new_pos_r][new_pos_c] == 1:  # Skip visited locations or walls
                continue

            visited[new_pos_r][new_pos_c] = 1

            queue_r.append(new_pos_r)
            queue_c.append(new_pos_c)

            nodes_in_next_layer += 1

        nodes_left_in_layer -= 1

        if nodes_left_in_layer == 0:
            move_count += 1
            nodes_left_in_layer = nodes_in_next_layer
            nodes_in_next_layer = 0


start_r, start_c = map(int, input().split())
end_r, end_c = map(int, input().split())

print(bfs(board, start_r-1, start_c-1, end_r-1, end_c-1))
