from collections import deque

walking_dist = 0
tele_distance = 0

board = []


def bfs(board, start_r, start_c):
    move_count = 0
    nodes_left_in_layer = 1
    nodes_in_next_layer = 0

    queue_r = deque()
    queue_c = deque()

    len_r = len(board[0])
    len_c = len(board)

    visited = [[0 for i in range(len_r)] for j in range(len_c)]

    # the BFS algorithm below
    queue_r.append(start_r)
    queue_c.append(start_c)

    visited[start_r][start_c] = 1

    while len(queue_r) > 0:
        current_pos_r = queue_r.popleft()
        current_pos_c = queue_c.popleft()

        if board[current_pos_r][current_pos_c] == "T":
            return move_count

        # direction vectors for N, S, E, and W
        r_move = [-1, 1, 0, 0]
        c_move = [0, 0, 1, -1]

        for i in range(4):
            new_pos_r = current_pos_r + r_move[i]
            new_pos_c = current_pos_c + c_move[i]

            if new_pos_r < 0 or new_pos_c < 0:  # Skip if the position outside of grid
                continue
            elif new_pos_r >= len_c or new_pos_c >= len_r:
                continue
            elif visited[new_pos_r][new_pos_c] == 1:  # Skip visited locations or walls
                continue
            elif board[new_pos_r][new_pos_c] == "X":
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


rows, columns = map(int, input().split())
start_r, start_c = map(int, input().split())
end_r, end_c = map(int, input().split())

for i in range(rows):
    board.append(list(input()))

# Temporarily setting office location as "T"
board[end_r][end_c] = "T"

walking_dist = bfs(board, start_r, start_c)

# Reset office location to original value
board[end_r][end_c] = "O"

num_teles = int(input())

for i in range(num_teles):
    end_r, end_c = map(int, input().split())
    board[end_r][end_c] = "T"

tele_distance = bfs(board, start_r, start_c)

print(walking_dist - tele_distance)
