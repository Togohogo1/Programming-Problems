import sys
input = sys.stdin.readline


def inverse(li):
    new = []

    for i in li:
        if i == 0:
            new.append(1)
        else:
            new.append(0)

    return new


move_count = 0
flag = False

flipper = []
moves = []

for i in range(int(input())):
    flipper.append(list(map(int, input().split())))

basecase = flipper[0]

for i in range(len(flipper)):
    if flipper[i] != inverse(basecase) and flipper[i] != basecase:
        flag = True
        print(-1)
        break

    if flipper[i] == inverse(basecase):
        moves.append(f"R {i + 1}")
        move_count += 1

if not flag:
    for i in range(len(basecase)):
        if basecase[i] == 1:
            moves.append(f"C {i + 1}")
            move_count += 1

    print(move_count)
    print("\n".join(moves))
