def quick_pow(b, n):
    final = 1

    while n > 0:
        if n % 2 == 1:  # Odd, multiply it by the result once then when // goes to one)
            final = (final * b) % 1_000_000_013

        # e.g ((a^2)^2)^... Do this log(n) times
        n //= 2
        b = (b**2) % 1_000_000_013

    return final

N = int(input())

if N == 1:
    print(1)
else:
    t1 = quick_pow(2, N-2)

    # A more generalized version would be quick_pow(2, N//2 - 1)
    if N % 2 == 0:
        t2 = quick_pow(2, (N-1) // 2)  # For both operations, include // due to precision errors (5e+17) vs 499_999_999_999_999_999
    elif N % 2 == 1:
        t2 = quick_pow(2, (N-2) // 2)

    # These segments of the cosine function returns 0
    if N % 8 in {2, 6}:
        t2 = 0
    # These (negative) segments of the cosine function returns -1 where N in root(2)^N is even or -root(2) where N in root(2)^N is odd
    elif N % 8 in {3, 4, 5}:
        t2 *= -1
    # This (positive) segment of the cosine function returns root(2) where N in root(2)^N is odd
    elif N % 8 in {0, 1, 7}:
        t2 *= 1

    print((t1 + t2) % 1_000_000_013)