for i in range(5):
    R, C, Ro = map(int, input().split())

    x_pos = set()
    y_pos = set()

    for i in range(Ro):
        rx, ry = map(int, input().split())
        x_pos.add(rx)
        y_pos.add(ry)

    print((R-len(x_pos)) * (C-len(y_pos)))
