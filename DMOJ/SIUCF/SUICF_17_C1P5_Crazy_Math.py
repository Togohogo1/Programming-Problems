def mat_mult(x, y):
    M = 1_000_000_000

    return [(x[0]*y[0] + x[1]*y[2]) % M,
            (x[0]*y[1] + x[1]*y[3]) % M,
            (x[2]*y[0] + x[3]*y[2]) % M,
            (x[2]*y[1] + x[3]*y[3]) % M]


def mat_pow(mat, power):
    base = [1, 1, 1, 0]

    if power <= 0:
        return [1, 0, 0, 1]

    for i in reversed(bin(power-1)[2:]):
        if i == "1":
            base = mat_mult(mat, base)

        mat = mat_mult(mat, mat)

    return base


n = int(input())
aux = mat_pow([1, 1, 1, 0], n)

print(mat_mult([3, 2, 2, 1], aux)[3] - 1)
