current = 0
fin_score = 0

comb_pts = {}

moves = input()
M = int(input())

fin_moves = moves


def find_idx(moves):
    idx = []

    for i in comb_sort:
        idx.append(moves.find(i))

    return idx


for i in range(M):
    combo, pts = map(str, input().split())
    comb_pts[combo] = int(pts)

comb_sort = sorted(comb_pts, key=len, reverse=True)

while len(moves):
    find_idx(moves)

    for i in find_idx(moves):
        if current == i:
            current = 0

            fin_score += comb_pts[comb_sort[find_idx(moves).index(i)]]

            index = len(comb_sort[find_idx(moves).index(i)])
            moves = moves[index:]

            break
    else:
        moves = moves[1:]

print(fin_score + len(fin_moves))
