import sys
from collections import defaultdict

input = sys.stdin.readline

nxt = {1: [3, 4], 2: [1, 2], 3: [3, 4], 4: [1, 2], 5: [3, 4], 6: [1, 2]}
fit = {1: 8, 2: 7, 3: 8, 4: 7, 5: 8, 6: 7}

pts = defaultdict(list)
puzzle = []

for i in range(int(input())):
    pcs_type, score = map(int, input().split())
    pts[pcs_type].append(score)

last1 = last4 = -1
count = 0
flag = True

puzzle.append((6, pts[6][0]) if 6 in pts else (5, pts[5][0]))

for i in pts:
    pts[i].sort()

while True:
    temp_min = 1000000001
    key_value = -1

    for i in nxt[puzzle[count][0]]:
        try:
            temp_min = min(temp_min, pts[i][0])
            if temp_min == pts[i][0]:
                key_value = i
        except:
            pass

    if key_value == 1:
        last1 = count + 1
    if key_value == 4:
        last4 = count + 1

    if not pts[key_value]:
        break

    puzzle.append((key_value, temp_min))
    pts[key_value].pop(0)

    count += 1

end = 8 if pts[8] else 7

if fit[puzzle[-1][0]] != end:
    print(-1)
else:
    puzzle.append((end, pts[end].pop()))

    for i in pts:
        if pts[i] and i in {1, 4}:
            print(-1)
            flag = False
            break

    if flag:
        for i in range(len(puzzle)):
            if i == last1:
                for j in pts[2]:
                    print(j, end=" ")
            if i == last4:
                for j in pts[3]:
                    print(j,  end=" ")

            print(puzzle[i][1], end=" ")
