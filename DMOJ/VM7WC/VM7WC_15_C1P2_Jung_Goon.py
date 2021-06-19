for i in range(int(input())):
    L = int(input())
    perm = list(map(int, input().split()))

    end = L - 1
    moves = 0

    for i in range(L, 0, -1):
        moves += abs(end - perm.index(i))
        perm.append(perm.pop(perm.index(i)))
        end -= 1

    print(moves)
