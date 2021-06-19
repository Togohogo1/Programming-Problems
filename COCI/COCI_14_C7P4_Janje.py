from math import factorial as f

def C(n, r):
    if n < r:
        return 0

    return f(n) // (f(r)*f(n-r))

N, K = map(int, input().split())

# 3*(2**19), pretty straightforward, subtract 6 at the end
# 6 chains are 1-2-1-2, 1-3-1-3, 2-3-2-3, 3-1-3-1, 3-2-3-2, 2-1-2-1
if N == 1:
    print(2*C(K, 2) + 1572858*C(K, 3))

# Simple calculations
elif N == 2:
    print(96*C(K, 3))

# Simple calculations
elif N == 3:
    print(2*C(K, 2) + 18*C(K, 3))

# Subtract 6 from the chains
elif N == 4:
    print(2*C(K, 2) + 24570*C(K, 3))

# Simple calculations
elif N == 5:
    print(12*C(K, 3))

# Easier than it looks. Only row 1 and 2 matter
elif N == 6:
    print(6*C(K, 3))

# Simple calculations
elif N == 7:
    print(96*C(K, 3))

# 3*(2**29), subtract 6 from the chains and subtract 3 times the 30th term of OEIS-A078008
elif N == 8:
    print(2*C(K, 2) + 1073741820*C(K, 3))
