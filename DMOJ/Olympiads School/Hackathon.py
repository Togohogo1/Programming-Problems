from math import ceil, floor
N, K = map(int, input().split())

for i in range(K):
    s, t, r = map(int, input().split())

    total = N/s
    breaks = total/t

    if breaks % 1 != 0:
        print(ceil(total + floor(breaks)*r))
    else:
        print(ceil(total + floor(breaks)*r - r))
