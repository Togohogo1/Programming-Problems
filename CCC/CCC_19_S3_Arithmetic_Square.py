from collections import namedtuple
from fractions import Fraction as fr
from random import randint


def ge(mat):
    r = 0
    c = 0
    mr = len(mat)  # Last row
    mc = len(mat[0])  # Last column

    while r < mr and c < mc:
        tmp_idx = -1

        # Finding pivot
        for i in range(r, mr):
            if mat[i][c] != 0:
                tmp_idx = i

        # No pivot in the col, move to next col
        if tmp_idx == -1:
            c += 1
        else:
            pivots.append(xdi[c])

            # Swapping
            mat[r], mat[tmp_idx] = mat[tmp_idx], mat[r]

            for i in range(r+1, mr):
                f = fr(mat[i][c]/mat[r][c])  # Factor for matrix operations
                mat[i][c] = 0  # Filling lower part of pivot with 0s

                # Do matrix operations on remaining elements in row
                for j in range(c+1, mc):
                    mat[i][j] -= mat[r][j] * f

            r += 1
            c += 1


def back_sub(mat):
    # Pivots are not assigned value
    for p in pivots:
        var_val[p] = None

    for row in mat:
        # Not row of empty values
        if row != [0]*10:
            ls = row[-1]  # Last value -> right hand side
            nonswing_coef = 0  # Coefficient of pivot
            let = None

            # loop to swing all "swingable" variables to other side
            for j, coef in enumerate(row[:-1]):
                if coef != 0:  # Value with coefficient
                    if var_val[xdi[j]] is not None:
                        ls -= coef*var_val[xdi[j]]  # Swing
                    else:
                        nonswing_coef = coef
                        let = xdi[j]

            # Value for new letter can be determined
            var_val[let] = ls/nonswing_coef


# Checks if is arithmetic square
def is_arith(a):
    return a[2]-a[1] == a[1]-a[0] and a[5]-a[4] == a[4]-a[3] and a[8]-a[7] == a[7]-a[6] \
       and a[6]-a[3] == a[3]-a[0] and a[7]-a[4] == a[4]-a[1] and a[8]-a[5] == a[5]-a[2]


sq = []
pivots = []
mat = [[0]*10 for _ in range(18)]
idx = {val:cnt for cnt, val in enumerate("xyzabcdef_")}
xdi = {cnt:val for cnt, val in enumerate("xyzabcdef_")}

'''
x x+d x+2d
y y+e y+2e
z z+f z+2f

x    x+d    x+2d
x+a  x+d+b  x+2d+c
x+2a x+d+2b x+2d+2c
'''
term = namedtuple("t", "cof var")
l = [
    [term(1, "x")],
    [term(1, "x"), term(1, "d")],
    [term(1, "x"), term(2, "d")],
    [term(1, "y")],
    [term(1, "y"), term(1, "e")],
    [term(1, "y"), term(2, "e")],
    [term(1, "z")],
    [term(1, "z"), term(1, "f")],
    [term(1, "z"), term(2, "f")],
]
r = [
    [term(1, "x")],
    [term(1, "x"), term(1, "d")],
    [term(1, "x"), term(2, "d")],
    [term(1, "x"), term(1, "a")],
    [term(1, "x"), term(1, "d"), term(1, "b")],
    [term(1, "x"), term(2, "d"), term(1, "c")],
    [term(1, "x"), term(2, "a")],
    [term(1, "x"), term(1, "d"), term(2, "b")],
    [term(1, "x"), term(2, "d"), term(2, "c")],
]

# Taking input
for i in range(3):
    sq += input().split()

ii = 0

# Populating array to do GE on
for count, value in enumerate(sq):
    # Setting LHS to RHS (one equation)
    if value == "X":
        for nt in l[count]:
            mat[ii][idx[nt.var]] += nt.cof

        for nt in r[count]:
            mat[ii][idx[nt.var]] -= nt.cof

        ii += 1

    # Setting LHS to value (one equation), then RHS to value (another equation)
    else:
        mat[ii][-1] = int(value)

        for nt in l[count]:
            mat[ii][idx[nt.var]] += nt.cof

        ii += 1

        mat[ii][-1] = int(value)

        for nt in r[count]:
            mat[ii][idx[nt.var]] += nt.cof

        ii += 1

# Do Gaussian elimination
ge(mat)

while True:
    art = []

    # RNG for free variables
    var_val = {val:randint(0, 10) for val in "xyzabcdef"}

    back_sub(reversed(mat))

    # Converts potential fractional values to integer
    for terms in l:
        ans = 0

        for nt in terms:
            ans += nt.cof*var_val[nt.var]

        art.append(int(ans*ans.denominator))

    if is_arith(art):
        print(f"{art[0]} {art[1]} {art[2]}\n \
                {art[3]} {art[4]} {art[5]}\n \
                {art[6]} {art[7]} {art[8]}")
        break
