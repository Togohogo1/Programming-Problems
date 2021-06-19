from math import ceil, log10
import sys

input = sys.stdin.readline


def dist(a, b, K):
    c = 0

    if K > 1:
        a_lay = ceil((log10((K-1)*a+1) / (log10(K))))
        b_lay = ceil((log10((K-1)*b+1) / (log10(K))))

        if a == 1:
            a_lay = 1
        if b == 1:
            b_lay = 1

        maA = max(a_lay, b_lay)
        miB = min(a_lay, b_lay)

        c = maA - miB

        if miB == 1:
            base = 1
        else:
            base = (K**(miB-1)-1)//(K-1) + 1

        ma = (max(a, b)-((K**(maA-1)-1)//(K-1)+1)) // (K**c)
        mi = min(a, b) - base

        while ma != mi:
            c += 2
            ma //= K
            mi //= K

    else:
        c = abs(a - b)

    return c


N, K, Q = map(int, input().split())

for i in range(Q):
    x, y = map(int, input().split())
    print(dist(x, y, K))
