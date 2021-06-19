board = ["ABCD", "EFGH", "IJKL", "MNO."]


def locate(n, grid):
    for i in range(4):
        for j in range(4):
            if grid[i][j] == n:
                return [i, j]


dist = 0
shuffle = []

for i in range(4):
    shuffle.append(input())

for i in shuffle:
    for j in i:
        if j != ".":
            dist += abs(locate(j, board)[0] - locate(j, shuffle)[0]) + abs(locate(j, board)[1] - locate(j, shuffle)[1])

print(dist)
