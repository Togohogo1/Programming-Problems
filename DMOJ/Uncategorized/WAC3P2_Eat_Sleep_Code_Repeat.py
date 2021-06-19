from math import floor, ceil


def max_produc(H):
    E = ceil(H/3)
    S = floor(H/3)
    C = H - E - S

    return E * S * C


for i in range(int(input())):
    print(max_produc(int(input())))
