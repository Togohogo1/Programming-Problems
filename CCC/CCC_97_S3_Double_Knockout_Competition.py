def split(n):
    if n != 1:
        return n - n//2, n//2

    return 1, 0


for i in range(int(input())):
    c = 0
    rnd = [0, 0, 0]

    rnd[0] = int(input())
    print(f"Round 0: {rnd[0]} undefeated, 0 one-loss, 0 eliminated")

    while rnd[0] != 1 or rnd[1] != 1:
        c += 1
        t0 = rnd[0]
        t1 = rnd[1]

        rnd[0] = split(t0)[0]
        rnd[1] = split(t0)[1]
        rnd[1] += split(t1)[0]
        rnd[2] += split(t1)[1]

        print(f"Round {c}: {rnd[0]} undefeated, {rnd[1]} one-loss, {rnd[2]} eliminated")

    print(f"Round {c+1}: 0 undefeated, 2 one-loss, {rnd[2]} eliminated")
    print(f"Round {c+2}: 0 undefeated, 1 one-loss, {rnd[2]+1} eliminated")
    print(f"There are {c+2} rounds.")
    print()
