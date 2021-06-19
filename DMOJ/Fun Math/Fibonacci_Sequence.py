def mat_mult(x, y):
    # 2 by 2 array * 1 by 1 array
    if len(y) == 2:
        a = x[0]*y[0] + x[1]*y[1]
        b = x[2]*y[0] + x[3]*y[1]

        return [a, b]

    # 2 by 2 array * 2 by 2 array
    else:
        a = x[0]*y[0] + x[1]*y[2]
        b = x[0]*y[1] + x[1]*y[3]
        c = x[2]*y[0] + x[3]*y[2]
        d = x[2]*y[1] + x[3]*y[3]

        return [a % 1000000007,
                b % 1000000007,
                c % 1000000007,
                d % 1000000007]


def mat_pow(x, n):
    if n == 1:
        return x
    elif n % 2 == 0:
        return mat_pow(mat_mult(x, x), n//2)
    else:
        return mat_mult(x, mat_pow(mat_mult(x, x), n//2))


# Original Matrices
original = [1, 1, 1, 0]
vector = [1, 0]

N = int(input())

print(mat_mult(mat_pow(original, N-1), vector)[0] % 1000000007)
