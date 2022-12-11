p = {
    ((0, 0, 0), (0, 0, 0), (0, 1, 0)): {
        (1, 1): ((0, 0, 0), (0, 0, 0), (0, 1, 0)),
        (2, 0): ((0, 0, 0), (0, 0, 1), (0, 1, 0)),
        (2, 2): ((0, 0, 0), (1, 0, 0), (0, 1, 0))
    },

    ((0, 0, 0), (0, 0, 1), (0, 1, 0)): {
        (0, 2): ((0, 0, 0), (0, 0, 1), (0, 1, 0)),
        (1, 1): ((0, 0, 0), (0, 0, 1), (0, 1, 0)),
        (2, 0): ((0, 0, 0), (0, 0, 1), (0, 1, 0)),
        (2, 2): ((0, 1, 0), (1, 0, 1), (0, 1, 0))
    },

    ((0, 0, 0), (1, 0, 0), (0, 1, 0)): {
        (0, 0): ((0, 0, 0), (1, 0, 0), (0, 1, 0)),
        (1, 1): ((0, 0, 0), (1, 0, 0), (0, 1, 0)),
        (2, 2): ((0, 0, 0), (1, 0, 0), (0, 1, 0)),
        (2, 0): ((0, 1, 0), (1, 0, 1), (0, 1, 0))
    },

    ((0, 1, 0), (1, 0, 1), (0, 1, 0)): {
        (0, 0): ((0, 1, 0), (1, 0, 1), (0, 1, 0)),
        (1, 1): ((0, 1, 0), (1, 0, 1), (0, 1, 0)),
        (2, 2): ((0, 1, 0), (1, 0, 1), (0, 1, 0)),
        (2, 0): ((0, 1, 0), (1, 0, 1), (0, 1, 0)),
        (0, 2): ((0, 1, 0), (1, 0, 1), (0, 1, 0))
    }
}


def f(ax, ay, width):
    cell = ((0, 0, 0), (0, 0, 0), (0, 1, 0))
    li = []

    while width != 1:
        li.append((ax, ay, width))
        ax //= 3
        ay //= 3
        width //= 3

    for ax, ay, width in li[::-1]:
        if 3**level < width or cell is None:
            break

        rr, rc = 2-(ay%3), ax%3  # Relative location of next zoom

        if cell[rr][rc] == 1:
            return True

        # Relative location of n
        cell = p[cell].get((rr, rc))

    return False


level, width, x = list(map(int, input().split()))

if x == 0 or x == width:
    print(1)
else:
    for i in range(width):
        bl = True if i == 0 else f(x-1, i-1, width)
        br = True if i == 0 else f(x, i-1, width)
        tl = f(x-1, i, width)
        tr = f(x, i, width)

        if not (bl == br == tl == tr):
            print(i+1, end=" ")
