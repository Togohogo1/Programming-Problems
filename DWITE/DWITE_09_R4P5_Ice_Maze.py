from collections import deque


def in_range(r, c):
    return (0 <= r < 10 and 0 <= c < 10 and br[r][c] != "#")


def bfs(start_r, start_c, end_r, end_c):
    dist = 0

    queue_r = deque()
    queue_c = deque()
    queue_d = deque()

    dir_r = [1, -1, 0, 0]
    dir_c = [0, 0, 1, -1]

    queue_r.append(start_r)
    queue_c.append(start_c)
    queue_d.append(0)

    while queue_r:
        curr_r = queue_r.popleft()
        curr_c = queue_c.popleft()
        dist = queue_d.popleft()

        if [curr_r, curr_c] == [end_r, end_c]:
            return dist

        for change_r, change_c in zip(dir_r, dir_c):
            new_r, new_c = curr_r, curr_c

            for i in range(100):
                # Once out of range, forces it to go back in range
                if not in_range(new_r, new_c):
                    new_r -= change_r
                    new_c -= change_c
                    i -= 1
                    break

                # Each time, adding different direction until out of range
                new_r += change_r
                new_c += change_c

            queue_r.append(new_r)
            queue_c.append(new_c)
            queue_d.append(dist+i)


cr = []
br = []

for i in range(10):
    br.append(list(input()))

for i in range(10):
    for j in range(10):
        if br[i][j] in "ABCDEF":
            cr.append([br[i][j], [i, j]])

cr.sort()

for i in range(5):
    print(bfs(cr[i][1][0], cr[i][1][1], cr[i+1][1][0], cr[i+1][1][1]))
