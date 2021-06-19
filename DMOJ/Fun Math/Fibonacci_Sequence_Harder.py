def mat_mult(x, y):
    M = 1_000_000_007

    # 2x2 array * 2x2 array
    return [(x[0]*y[0] + x[1]*y[2]) % M,
            (x[0]*y[1] + x[1]*y[3]) % M,
            (x[2]*y[0] + x[3]*y[2]) % M,
            (x[2]*y[1] + x[3]*y[3]) % M]


def mat_pow(mat, power):
    base = [1, 1, 1, 0]

    # Binary representation
    for i in reversed(bin(power)[2:]):
        if i == "1":
            base = mat_mult(base, mat)

        mat = mat_mult(mat, mat)

    return base


print(mat_pow([1, 1, 1, 0], int(input()))[3])
