def diff(p1, p2):
    dx = abs(p1[0] - p2[0])
    dy = abs(p1[1] - p2[1])
    dz = abs(p1[2] - p2[2])

    return (dx + dy + dz)


for _ in range(5):
    m = 0
    comets = []

    for _ in range(int(input())):
        A, B, C, D, E, F, G, H, I, U, V = map(int, input().split())

        for t in [U, V]:
            x = A*(t**2) + B*t + C
            y = D*(t**2) + E*t + F
            z = G*(t**2) + H*t + I

            comets.append([x, y, z])

    for p1 in comets:
        for p2 in comets:
            m = max(m, diff(p1, p2))

    print(m)
